#include <TankTek/render/AssetLoader.hpp>
#include <TankTek/render/RawModel.hpp>
#include <TankTek/Logger.hpp>
#include <TankTek/objects/Texture.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <glad/glad.h>

namespace TankTek
{
    RawModel* AssetLoader::loadToVAO(std::vector<float> positions, std::vector<unsigned int> indices, std::vector<float> texCoords)
    {
        unsigned int vaoID = this->createVAO();
        this->bindIndicesBuffer(indices);
        this->storeDataInAttributeList(0, 3, positions);
        this->storeDataInAttributeList(1, 2, texCoords);
        this->unbindVAO();
        return new RawModel(vaoID, indices.size());
    }

    Texture* AssetLoader::loadTexture(const std::string& filePath)
    {
        unsigned int textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        // Set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // Load and generate the texture
        int width, height, nrChannels;
        unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            if (nrChannels == 3)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            }
            else if (nrChannels == 4)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            }
            else
            {
                Logger::error("Unknown number of channels in texture: " + filePath);
            }
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            Logger::error("Failed to load texture: " + filePath);
        }
        stbi_image_free(data);
        return new TankTek::Texture(textureID);
    }

    void AssetLoader::cleanUp()
    {
        for(unsigned int vao : this->vaos) {
            glDeleteVertexArrays(1, &vao);
        }
        for(unsigned int vbo : this->vbos) {
            glDeleteBuffers(1, &vbo);
        }
    }

    unsigned int AssetLoader::createVAO()
    {
        unsigned int vaoID;
        glGenVertexArrays(1, &vaoID);
        this->vaos.push_back(vaoID);
        glBindVertexArray(vaoID);
        return vaoID;
    }

    void AssetLoader::storeDataInAttributeList(int attributeNumber, int coordSize, std::vector<float> data)
    {
        unsigned int vboID;
        glGenBuffers(1, &vboID);
        this->vbos.push_back(vboID);
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, coordSize, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void AssetLoader::bindIndicesBuffer(std::vector<unsigned int> indices)
    {
        unsigned int vboID;
        glGenBuffers(1, &vboID);
        this->vbos.push_back(vboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    }

    void AssetLoader::unbindVAO()
    {
        glBindVertexArray(0);
    }
}