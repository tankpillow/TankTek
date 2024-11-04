#ifndef TT_PrimitiveMesh_HPP_
#define TT_PrimitiveMesh_HPP_

#include <TankTek/objects/Component.hpp>
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
            PrimitiveType type;
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            RawModel* model;
        public:
            PrimitiveMesh(PrimitiveType type);
            ~PrimitiveMesh();
        public:
            void onStart() override;
            void onUpdate() override;
            void onRender() override;
            void onStop() override;
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