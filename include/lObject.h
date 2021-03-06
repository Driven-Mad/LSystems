#ifndef LOBJECT_H
#define LOBJECT_H
#include <vector>
#include <ngl/Vec4.h>
//--------------------------------------------------------------------------------------------------------------------------
/// @file lObject.h
/// @brief This is the lObject class specifically for storing and handling of objects created
/// by an lSystem.
/// @author Lloyd Phillips
/// @version 0.1
/// @date 25/01/17
/// Revision History:
/// currently WIP, only holds raw verts and indicies, not final array of points.
/// @class lObject
/// @brief The class for storing lSystem data and handling.
//--------------------------------------------------------------------------------------------------------------------------
class lObject
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for lObject class
    //----------------------------------------------------------------------------------------------------------------------
    lObject();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor for turtle class
    //----------------------------------------------------------------------------------------------------------------------
    ~lObject();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief add a vert to our raw verticies.
    /// @param v the vector you wish to add to our verts (vec4)
    //----------------------------------------------------------------------------------------------------------------------
    void addVert(ngl::Vec4 v){m_rawVerts.push_back(v);}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief add an indicie to our indicies.
    /// @param i the indicie you wish to add to our indicies (int)
    //----------------------------------------------------------------------------------------------------------------------
    void addIndicies(int i){m_indicies.push_back(i);}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief returns the size of our indicies array
    /// @return m_indicies.size
    //----------------------------------------------------------------------------------------------------------------------
    int iSize(){return m_indicies.size();}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief clears both our verticies and indicies arrays.
    //----------------------------------------------------------------------------------------------------------------------
    void clearAll(){m_rawVerts.clear(); m_indicies.clear();}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief retrieves a indicie
    /// @param i the location that you want to retrieve the indicie from in our indicie array.
    /// @return m_indicies[i]
    //----------------------------------------------------------------------------------------------------------------------
    int getIndicie(int i){return m_indicies[i];}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief retrieves a vertex
    /// @param i the location that you want to retrieve the vertex from in our vertex array.
    /// @return m_rawVerts[i]
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec4 getVertex(int i){return m_rawVerts[i];}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief retrieves the vertex array
    /// @return m_rawVerts
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<ngl::Vec4> getVerticies(){return m_rawVerts;}

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief gets the amount of verts
    /// @return Returns the size of the array storing our verts
    //----------------------------------------------------------------------------------------------------------------------
    int getVertsSize(){return m_rawVerts.size();}

private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief verticies produced by a turtle.
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<ngl::Vec4> m_rawVerts;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief indicies produced by a turtle.
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<int> m_indicies;

};

#endif
