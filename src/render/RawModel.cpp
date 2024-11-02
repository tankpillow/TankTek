#include <TankTek/render/RawModel.hpp>

namespace TankTek
{
    RawModel::RawModel(unsigned int vaoID, unsigned int vertexCount)
    {
        this->vaoID = vaoID;
        this->vertexCount = vertexCount;
    }

    unsigned int RawModel::getVaoID()
    {
        return this->vaoID;
    }

    unsigned int RawModel::getVertexCount()
    {
        return this->vertexCount;
    }
}