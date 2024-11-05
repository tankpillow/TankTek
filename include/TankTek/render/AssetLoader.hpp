#ifndef TT_ModelLoader_HPP_
#define TT_ModelLoader_HPP_

#include <vector>
#include <string>

namespace TankTek
{
    class RawModel;
    class Texture;

    class AssetLoader
    {
        private:
            std::vector<unsigned int> vaos;
            std::vector<unsigned int> vbos;
            std::vector<unsigned int> textures;
        public:
            RawModel* loadToVAO(std::vector<float> positions, std::vector<unsigned int> indices, std::vector<float> texCoords);
            Texture* loadTexture(const std::string& filePath);
            void cleanUp();
        private:
            unsigned int createVAO();
            void storeDataInAttributeList(int attributeNumber, int coordSize, std::vector<float> data);
            void bindIndicesBuffer(std::vector<unsigned int> indices);
            void unbindVAO();
    };
}

#endif