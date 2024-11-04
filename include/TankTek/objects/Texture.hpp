#ifndef TT_Texture_HPP_
#define TT_Texture_HPP_

namespace TankTek
{
    class Texture
    {
        private:
            unsigned int textureID;
        public:
            Texture(unsigned int textureID);
            ~Texture();
        public:
            unsigned int getTextureID();

    };
}

#endif