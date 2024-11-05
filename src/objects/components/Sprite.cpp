#include <TankTek/objects/components/Sprite.hpp>
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
    Sprite::Sprite(GameObject* gameObject) : Component(gameObject)
    {
        this->texture = nullptr;
    }

    Sprite::~Sprite()
    {
        delete this->texture;
    }

    void Sprite::setTexture(Texture* texture)
    {
        this->texture = texture;
    }

    void Sprite::onStart()
    {
        this->vertices = {
            -0.5f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f
        };

        this->indices = {
            0, 1, 3,
            3, 1, 2
        };

        this->texCoords = {
            0.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f
        };

        this->model = TankTek::Application::getInstance()->assetLoader->loadToVAO(this->vertices, this->indices, this->texCoords);
    }

    void Sprite::onUpdate()
    {}

    void Sprite::onRender()
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

    void Sprite::onStop()
    {
        delete this->model;
    }
}