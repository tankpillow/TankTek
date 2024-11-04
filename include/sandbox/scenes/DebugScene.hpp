#ifndef SB_DebugScene_HPP_
#define SB_DebugScene_HPP_

#include <TankTek/TankTek.hpp>

class DebugScene : public TankTek::Scene
{
    private:
        TankTek::RawModel* model;
    public:
        DebugScene();
        ~DebugScene();
    public:
        void onStart() override;
        void onUpdate() override;
        void onRender() override;
        void onStop() override;
};

#endif