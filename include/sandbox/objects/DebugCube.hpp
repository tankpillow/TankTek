#ifndef SB_DebugCube_HPP_
#define SB_DebugCube_HPP_

#include <TankTek/TankTek.hpp>

class DebugCube : public TankTek::GameObject
{
    public:
        DebugCube();
        ~DebugCube();
    public:
        void onStart() override;
        void onUpdate() override;
        void onRender() override;
        void onStop() override;
};

#endif