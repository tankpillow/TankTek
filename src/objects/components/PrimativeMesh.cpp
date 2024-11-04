#include <TankTek/objects/components/PrimativeMesh.hpp>
#include <TankTek/Application.hpp>
#include <TankTek/render/RawModel.hpp>
#include <TankTek/render/AssetLoader.hpp>
#include <TankTek/render/Renderer.hpp>
#include <TankTek/Logger.hpp>

namespace TankTek
{
    PrimitiveMesh::PrimitiveMesh() : Component()
    {
        
    }

    PrimitiveMesh::~PrimitiveMesh()
    {}

    void PrimitiveMesh::onStart()
    {
        switch(this->type)
        {
            case PrimitiveType::CUBE: 
                this->createCube();
                break;
            case PrimitiveType::SPHERE:
                this->createSphere();
                break;
            case PrimitiveType::PLANE:
                this->createPlane();
                break;
            case PrimitiveType::QUAD:
                this->createQuad();
                break;
            case PrimitiveType::CYLINDER:
                this->createCylinder();
                break;
            case PrimitiveType::CONE:
                this->createCone();
                break;
        }

        TankTek::Logger::info("Creating Primitive Mesh!");
        // this->model = TankTek::Application::getInstance()->assetLoader->loadToVAO(this->vertices, this->indices);
        TankTek::Logger::info("Primitive Mesh Created!");
    }

    void PrimitiveMesh::onUpdate()
    {}

    void PrimitiveMesh::onRender()
    {
        TankTek::Application::getInstance()->renderer->render(this->model);
    }

    void PrimitiveMesh::onStop()
    {}

    void PrimitiveMesh::setType(PrimitiveType type)
    {
        this->type = type;
    }

    void PrimitiveMesh::setSize(Vec2f size)
    {
        this->size = size;
    }

    void PrimitiveMesh::createCube()
    {
        Logger::error("Cube Not Implemented!");
    }

    void PrimitiveMesh::createSphere()
    {
        Logger::error("Sphere Not Implemented!");
    }

    void PrimitiveMesh::createPlane()
    {
        Logger::error("Plane Not Implemented!");
    }

    void PrimitiveMesh::createQuad()
    {
        this->vertices = {
            -this->size.x, this->size.x, 0.0f,
            -this->size.x, -this->size.x, 0.0f,
            this->size.x, -this->size.x, 0.0f,
            this->size.x, this->size.x, 0.0f,
        };

        this->indices = {
            0, 1, 3,
            3, 1, 2
        };
    }

    void PrimitiveMesh::createCylinder()
    {
        Logger::error("Cylinder Not Implemented!");
    }

    void PrimitiveMesh::createCone()
    {
        Logger::error("Cone Not Implemented!");
    }

}