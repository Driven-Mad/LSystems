#ifndef LOBJECT_H
#define LOBJECT_H
#include <vector>
#include <ngl/Vec4.h>

class lObject
{
public:
    lObject();
    ~lObject();
    void addVert(ngl::Vec4 v){m_rawVerts.push_back(v);}
    void addIndicies(int i){m_indicies.push_back(i);}
    int iSize(){return m_indicies.size();}
    void clearAll(){m_rawVerts.clear(); m_indicies.clear();}
    int getIndicie(int i){return m_indicies[i];}
    ngl::Vec4 getVertex(int i){return m_rawVerts[i];}

private:
    std::vector<ngl::Vec4> m_rawVerts; ///< verticies produced by a turtle.
    std::vector<int> m_indicies; ///< verticies produced by a turtle.


};

#endif
