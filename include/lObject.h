#ifndef LOBJECT_H
#define LOBJECT_H
#include <vector>
#include <ngl/Vec2.h>
#include <ngl/Vec3.h>

class lObject
{
public:
    lObject();
    ~lObject();
    void addVert(ngl::Vec3 v){m_verts.push_back(v);};

private:
    std::vector<ngl::Vec3> m_verts; ///< verticies produced by a turtle.


};

#endif
