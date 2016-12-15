#ifndef OBJECT_H
#define OBJECT_H
#include <vector>
#include <ngl/Vec2.h>
#include <ngl/Vec3.h>

class object
{
public:
    object();
    ~object();

    /// \brief sets position
    void setPosition(ngl::Vec3 p_pos){m_position=p_pos;};
    /// \brief sets rotation
    void setRotation(ngl::Vec3 p_rot){m_rotation =p_rot;};
    /// \brief gets position
    ngl::Vec3 getPosition(){return m_position;};
    /// \brief gets rotation
    /// \return m_rotation
    ngl::Vec3 getRotation(){return m_rotation;};

    void addVert(ngl::Vec3 p_vert){m_verts.push_back(p_vert);};
    void addUV(ngl::Vec2 p_UV){m_UVs.push_back(p_UV);};
    void addNormal(ngl::Vec3 p_normal){m_normals.push_back(p_normal);};
    void addTangent(ngl::Vec3 p_tangent){m_tangents.push_back(p_tangent);};
    void addbiTangents(ngl::Vec3 p_biTangent){m_biTangents.push_back(p_biTangent);};

    void printVerticies();



private:
    ngl::Vec3 m_position; ///< Position of model
    ngl::Vec3 m_rotation; ///< Rotation of model
    std::vector<ngl::Vec3> m_verts; ///< verticies produced parser
    std::vector<ngl::Vec2> m_UVs;///< UVS produced from parser
    std::vector<ngl::Vec3> m_normals;///< Normals produced parser
    std::vector<ngl::Vec3> m_tangents;///< Tangents produced parser
    std::vector<ngl::Vec3> m_biTangents;///< BiTangents produced parser
};

#endif
