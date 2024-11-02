#ifndef TT_ModelLoader_HPP_
#define TT_ModelLoader_HPP_

#include <vector>

namespace TankTek
{
    class RawModel;

    class ModelLoader
    {
        private:
            std::vector<unsigned int> vaos;
            std::vector<unsigned int> vbos;
        public:
            RawModel* loadToVAO(std::vector<float> positions, std::vector<unsigned int> indices);
            void cleanUp();
        private:
            unsigned int createVAO();
            void storeDataInAttributeList(int attributeNumber, std::vector<float> data);
            void bindIndicesBuffer(std::vector<unsigned int> indices);
            void unbindVAO();
    };
}

#endif