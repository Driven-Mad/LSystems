#ifndef OBJECT_H
#define OBJECT_H
#include <vector>
#include "lMath.h"

class object
{
public:
    object();
    ~object();

    /// \brief sets position
    void setPosition(Vec3 p_pos){m_position=p_pos};
    /// \brief sets rotation
    void setRotation(Vec3 p_rot){m_rotation =p_rot};
    /// \brief gets position
    Vec3 getPosition(){return m_position;};
    /// \brief gets rotation
    Vec3 getRotation(){return m_rotation;};;
private:
    Vec3 m_position; ///< Position of model
    Vec3 m_rotation; ///< Rotation of model
    std::vector<Vec3> m_verts; ///< verticies produced parser
    std::vector<Vec2> m_UVs;///< UVS produced from parser
    std::vector<Vec3> m_normals;///< Normals produced parser
    std::vector<Vec3> m_tangents;///< Tangents produced parser
    std::vector<Vec3> m_biTangents;///< BiTangents produced parser
};

#endif
