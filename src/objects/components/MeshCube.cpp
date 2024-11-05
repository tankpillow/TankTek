#include <TankTek/objects/components/MeshCube.hpp>
#include <TankTek/render/RawModel.hpp>
#include <TankTek/render/AssetLoader.hpp>
#include <TankTek/render/Renderer.hpp>
#include <TankTek/Logger.hpp>
#include <TankTek/objects/Texture.hpp>
#include <TankTek/Application.hpp>
#include <TankTek/math/Math.hpp>
#include <TankTek/objects/GameObject.hpp>
#include <TankTek/render/shaders/StaticShader.hpp>

#include <glad/glad.h>

#include <sstream>

namespace TankTek
{   
    MeshCube::MeshCube(GameObject* gameObject) : Component(gameObject)
    {
        this->texture = nullptr;
    }

    MeshCube::~MeshCube()
    {
        delete this->texture;
    }

    void MeshCube::setTexture(Texture* texture)
    {
        this->texture = texture;
    }

    void MeshCube::onStart()
    {
        this->vertices = {
            -0.5f,0.5f,-0.5f,	
            -0.5f,-0.5f,-0.5f,	
            0.5f,-0.5f,-0.5f,	
            0.5f,0.5f,-0.5f,		
            
            -0.5f,0.5f,0.5f,	
            -0.5f,-0.5f,0.5f,	
            0.5f,-0.5f,0.5f,	
            0.5f,0.5f,0.5f,
            
            0.5f,0.5f,-0.5f,	
            0.5f,-0.5f,-0.5f,	
            0.5f,-0.5f,0.5f,	
            0.5f,0.5f,0.5f,
            
            -0.5f,0.5f,-0.5f,	
            -0.5f,-0.5f,-0.5f,	
            -0.5f,-0.5f,0.5f,	
            -0.5f,0.5f,0.5f,
            
            -0.5f,0.5f,0.5f,
            -0.5f,0.5f,-0.5f,
            0.5f,0.5f,-0.5f,
            0.5f,0.5f,0.5f,
            
            -0.5f,-0.5f,0.5f,
            -0.5f,-0.5f,-0.5f,
            0.5f,-0.5f,-0.5f,
            0.5f,-0.5f,0.5f

        };

        this->indices = {
            0,1,3,	
            3,1,2,	
            4,5,7,
            7,5,6,
            8,9,11,
            11,9,10,
            12,13,15,
            15,13,14,	
            16,17,19,
            19,17,18,
            20,21,23,
            23,21,22
        };

        this->texCoords = {
            0,0,
            0,1,
            1,1,
            1,0,			
            0,0,
            0,1,
            1,1,
            1,0,			
            0,0,
            0,1,
            1,1,
            1,0,
            0,0,
            0,1,
            1,1,
            1,0,
            0,0,
            0,1,
            1,1,
            1,0,
            0,0,
            0,1,
            1,1,
            1,0
        };

        this->model = TankTek::Application::getInstance()->assetLoader->loadToVAO(this->vertices, this->indices, this->texCoords);
    }

    void MeshCube::onUpdate()
    {}

    void MeshCube::onRender()
    {
        glBindVertexArray(this->model->getVaoID());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        Matrix4 transform = Math::createTransform(this->gameObject->position, this->gameObject->rotation, this->gameObject->scale);
        TankTek::Application::getInstance()->shader->loadTransformationMatrix(transform);   

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->texture->getTextureID());
        glDrawElements(GL_TRIANGLES, this->model->getVertexCount(), GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    void MeshCube::onStop()
    {
        delete this->model;
    }

}