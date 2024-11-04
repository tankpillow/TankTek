#ifndef SB_DebugSquare_HPP_
#define SB_DebugSquare_HPP_

#include <TankTek/TankTek.hpp>

class DebugSquare : public TankTek::GameObject
{
    public:
        DebugSquare();
        ~DebugSquare();
    public:
        void onStart() override;
        void onUpdate() override;
        void onRender() override;
        void onStop() override;
};

#endif