#include <TankTek/render/ModelLoader.hpp>
#include <TankTek/render/RawModel.hpp>

#include <glad/glad.h>

namespace TankTek
{
    RawModel* ModelLoader::loadToVAO(std::vector<float> positions, std::vector<unsigned int> indices)
    {
        unsigned int vaoID = this->createVAO();
        this->bindIndicesBuffer(indices);
        this->storeDataInAttributeList(0, positions);
        this->unbindVAO();
        return new RawModel(vaoID, indices.size());
    }

    void ModelLoader::cleanUp()
    {
        for(unsigned int vao : this->vaos) {
            glDeleteVertexArrays(1, &vao);
        }
        for(unsigned int vbo : this->vbos) {
            glDeleteBuffers(1, &vbo);
        }
    }

    unsigned int ModelLoader::createVAO()
    {
        unsigned int vaoID;
        glGenVertexArrays(1, &vaoID);
        this->vaos.push_back(vaoID);
        glBindVertexArray(vaoID);
        return vaoID;
    }

    void ModelLoader::storeDataInAttributeList(int attributeNumber, std::vector<float> data)
    {
        unsigned int vboID;
        glGenBuffers(1, &vboID);
        this->vbos.push_back(vboID);
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void ModelLoader::bindIndicesBuffer(std::vector<unsigned int> indices)
    {
        unsigned int vboID;
        glGenBuffers(1, &vboID);
        this->vbos.push_back(vboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    }

    void ModelLoader::unbindVAO()
    {
        glBindVertexArray(0);
    }
}