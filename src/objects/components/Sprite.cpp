#include <TankTek/objects/components/Sprite.hpp>
#include <TankTek/render/RawModel.hpp>
#include <TankTek/render/AssetLoader.hpp>
#include <TankTek/render/Renderer.hpp>
#include <TankTek/Logger.hpp>
#include <TankTek/objects/Texture.hpp>
#include <TankTek/Application.hpp>
#include <TankTek/render/shaders/SpriteShader.hpp>

#include <glad/glad.h>

namespace TankTek
{
    Sprite::Sprite() : Component()
    {
        this->texture = nullptr;
        this->shader = new SpriteShader();
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
        this->shader->start();
        this->render();
        this->shader->stop();
    }

    void Sprite::onStop()
    {}

    void Sprite::render()
    {
        glBindVertexArray(this->model->getVaoID());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->texture->getTextureID());
        glDrawElements(GL_TRIANGLES, this->model->getVertexCount(), GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
    }
}