#ifndef TT_PrimitiveMesh_HPP_
#define TT_PrimitiveMesh_HPP_

#include <TankTek/objects/Component.hpp>
#include <TankTek/math/Vec2f.hpp>
#include <vector>

namespace TankTek
{
    class RawModel;

    enum class PrimitiveType
    {
        CUBE,
        SPHERE,
        PLANE,
        QUAD,
        CYLINDER,
        CONE
    };

    class PrimitiveMesh : public TankTek::Component
    {
        private:
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            RawModel* model;
        private:
            PrimitiveType type;
            Vec2f size;
        public:
            PrimitiveMesh();
            ~PrimitiveMesh();
        public:
            void onStart() override;
            void onUpdate() override;
            void onRender() override;
            void onStop() override;
        public:
            void setType(PrimitiveType type);
            void setSize(Vec2f size);
        private:
            void createCube();
            void createSphere();
            void createPlane();
            void createQuad();
            void createCylinder();
            void createCone();
    };
}

#endif