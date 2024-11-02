#ifndef TT_EntryPoint_HPP_
#define TT_EntryPoint_HPP_

#include <TankTek/TankTek.hpp>

extern TankTek::Application* TankTek::createApplication();

int main(int argc, char* argv[])
{
    auto app = TankTek::createApplication();
    app->run();
    delete app;
    return 0;
}

#endif