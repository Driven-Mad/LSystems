#include "object.h"
object::object(){

}

object::~object(){

}

void object::printVerticies()
{
    for (size_t i = 0; i< m_verts.size(); i++)
    {
        printf("X: %f , Y: %f, Z: %f \n",m_verts[i].m_x, m_verts[i].m_y,m_verts[i].m_z );
    }
}
