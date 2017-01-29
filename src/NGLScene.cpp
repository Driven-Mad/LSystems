#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <iostream>

NGLScene::NGLScene()
{
  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
  setTitle("Blank NGL");
  pars = new lParser();
  lsys = new lSystem();
  pars->loadLSystem("LSystemFiles/lsystem.txt","LSystemFiles/rules.txt",*lsys);
}


NGLScene::~NGLScene()
{
    glDeleteProgram(myShader);
    std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}



void NGLScene::resizeGL(int _w , int _h)
{
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
}


void NGLScene::initializeGL()
{

  ngl::Vec3 from( -2, 2, -2);
  ngl::Vec3 to( 0, 0, -1 );
  ngl::Vec3 up( 0, 1, 0 );
    // now load to our new camera
  m_cam.set( from, to, up );
  // set the shape using FOV 45 Aspect Ratio based on Width and Height
  // The final two are near and far clipping planes of 0.5 and 10
  m_cam.setShape( 45.0f, 720.0f / 576.0f, 0.05f, 350.0f );
  // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
  // be done once we have a valid GL context but before we call any GL commands. If we dont do
  // this everything will crash
  ngl::NGLInit::instance();
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);


  lsys->stringInterpertator(lsys->getLSystem());

  glGenVertexArrays(1, &m_vaoID);
  // now bind a vertex array object for our verts
  glBindVertexArray(m_vaoID);
  // now we are going to bind this to our vbo

  glGenBuffers(1, &vboID);
  // now bind this to the VBO buffer
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  // allocate the buffer data
  glBufferData(GL_ARRAY_BUFFER, lsys->getGeneratedObject().getVertsSize()* sizeof(ngl::Vec4), &lsys->getGeneratedObject().getVerticies()[0], GL_DYNAMIC_DRAW);
  // now fix this to the attribute buffer 0
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ngl::Vec4), 0);
  // enable and bind this attribute (will be inPosition in the shader)
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);

  //create our shader.
  myShader = pars->loadProgram("Shaders/vertexShader.txt","Shaders/fragmentShader.txt");
  glUseProgram(myShader);


  //save out our locations
  MLocation     = glGetUniformLocation( myShader, "M" );
  MVPLocation   = glGetUniformLocation( myShader, "MVP" );
  colorLocation = glGetUniformLocation( myShader, "C" );


}



void NGLScene::paintGL()
{
    //mouse settings
    ngl::Mat4 rotX;
    ngl::Mat4 rotY;
    // create the rotation matrices
    rotX.rotateX( m_win.spinXFace );
    rotY.rotateY( m_win.spinYFace );
    // multiply the rotations
    m_mouseGlobalTX = rotY * rotX;
    // add the translations
    m_mouseGlobalTX.m_m[ 3 ][ 0 ] = m_modelPos.m_x;
    m_mouseGlobalTX.m_m[ 3 ][ 1 ] = m_modelPos.m_y;
    m_mouseGlobalTX.m_m[ 3 ][ 2 ] = m_modelPos.m_z;

    ngl::Mat4 MVP;
    ngl::Mat4 M;

    M = m_mouseGlobalTX;
    MVP = M * m_cam.getVPMatrix();
    ngl::Vec4 colour = ngl::Vec4(0.0,1.0,0.0,1.0);
    glUniform4fv(colorLocation,1,&colour[0]);

    glUniformMatrix4fv(MLocation, 1, GL_FALSE, M.openGL());
    glUniformMatrix4fv(MVPLocation, 1, GL_FALSE, MVP.openGL() );

    // clear the screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_win.width,m_win.height);
    glBindVertexArray(m_vaoID);		// select first bind the array
    glPointSize(5.0f);
    glDrawArrays(GL_LINES, 0,lsys->getGeneratedObject().getVertsSize());	// draw object

}

//----------------------------------------------------------------------------------------------------------------------

void NGLScene::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
  // escape key to quite
  case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  case Qt::Key_Space :
      m_win.spinXFace=0;
      m_win.spinYFace=0;
      m_modelPos.set(ngl::Vec3::zero());
  break;
  case Qt::Key_W : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
  case Qt::Key_S : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
  case Qt::Key_1 : glVertexAttrib3f(1,1,0,0); break;
  case Qt::Key_2 : glVertexAttrib3f(1,0,1,0); break;
  case Qt::Key_3 : glVertexAttrib3f(1,0,0,1); break;
  case Qt::Key_4 :
      //BoxFractal
      lsys->Reset();
      pars->loadLSystem("LSystemFiles/BoxFractalS.txt", "LSystemFiles/BoxFractalR.txt",*lsys);
      lsys->stringInterpertator(lsys->getLSystem());
      sendVertsToOpenGL();
      break;
  case Qt::Key_5 :
      //Box
      lsys->Reset();
      pars->loadLSystem("LSystemFiles/BoxS.txt", "LSystemFiles/BoxR.txt",*lsys);
      lsys->stringInterpertator(lsys->getLSystem());
      sendVertsToOpenGL();
      break;
  case Qt::Key_6 :
      //KockCurve
      lsys->Reset();
      pars->loadLSystem("LSystemFiles/KockCurveS.txt", "LSystemFiles/KockCurveR.txt",*lsys);
      lsys->stringInterpertator(lsys->getLSystem());
      sendVertsToOpenGL();
      break;
  case Qt::Key_7 :
      //KockSnowflake
      lsys->Reset();
      pars->loadLSystem("LSystemFiles/KockSnowflakeS.txt", "LSystemFiles/KockSnowflakeR.txt",*lsys);
      lsys->stringInterpertator(lsys->getLSystem());
      sendVertsToOpenGL();
      break;
  case Qt::Key_8 :
      //PleasentError
      lsys->Reset();
      pars->loadLSystem("LSystemFiles/PleasentErrorS.txt", "LSystemFiles/PleasentErrorR.txt",*lsys);
      lsys->stringInterpertator(lsys->getLSystem());
      sendVertsToOpenGL();
      break;
  case Qt::Key_9 :
      //Rings
      lsys->Reset();
      pars->loadLSystem("LSystemFiles/RingsS.txt", "LSystemFiles/RingsR.txt",*lsys);
      lsys->stringInterpertator(lsys->getLSystem());
      sendVertsToOpenGL();
      break;
  case Qt::Key_I:
      lsys->increaseGeneration();
      sendVertsToOpenGL();
      break;
  case Qt::Key_K:
      lsys->decreaseGeneration();
      sendVertsToOpenGL();

      break;
  case Qt::Key_P:
      lsys->printAll();
      break;
  case Qt::Key_Semicolon:
      pars->writeLSystem(*lsys);
      break;


  default : break;
  }
  // finally update the GLWindow and re-draw

    update();
}

void NGLScene::sendVertsToOpenGL()
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, lsys->getGeneratedObject().getVertsSize() * sizeof(ngl::Vec4), &lsys->getGeneratedObject().getVerticies()[0], GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ngl::Vec4), 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray( 0 );
}
