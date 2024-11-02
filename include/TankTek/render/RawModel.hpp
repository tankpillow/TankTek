#ifndef TT_RawModel_HPP_
#define TT_RawModel_HPP_

namespace TankTek
{
    class RawModel
    {
        private:
            unsigned int vaoID;
            unsigned int vertexCount;
        public:
            RawModel(unsigned int vaoID, unsigned int vertexCount);
        public:
            unsigned int getVaoID();
            unsigned int getVertexCount();
    };
}


#endif