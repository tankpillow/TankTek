#ifndef TT_Renderer_HPP_
#define TT_Renderer_HPP_

namespace TankTek
{

    class RawModel;

    class Renderer
    {
        public:
            void prepareFrame();
            void render(RawModel* model);
    };
}

#endif