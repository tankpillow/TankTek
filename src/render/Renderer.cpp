#include <TankTek/render/Renderer.hpp>
#include <TankTek/render/RawModel.hpp>  

#include <glad/glad.h>

namespace TankTek
{
    void Renderer::prepareFrame()
    {
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}