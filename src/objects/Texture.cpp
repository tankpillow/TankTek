#include <TankTek/objects/Texture.hpp>

namespace TankTek
{
    Texture::Texture(unsigned int textureID) : textureID(textureID)
    {}

    Texture::~Texture()
    {}

    unsigned int Texture::getTextureID()
    {
        return this->textureID;
    }
}