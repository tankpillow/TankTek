#include <TankTek/render/RawModel.hpp>

namespace TankTek
{
    RawModel::RawModel(unsigned int vaoID, unsigned int vertexCount) : vaoID(vaoID), vertexCount(vertexCount)
    {}

    unsigned int RawModel::getVaoID()
    {
        return this->vaoID;
    }

    unsigned int RawModel::getVertexCount()
    {
        return this->vertexCount;
    }
}