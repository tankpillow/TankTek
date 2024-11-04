#ifndef TT_Vec2f_HPP_
#define TT_Vec2f_HPP_

namespace TankTek
{
    class Vec2f
    {
        public:
            float x;
            float y;
        public:
            Vec2f();
            Vec2f(Vec2f& vec);
            Vec2f(float x, float y);
    };
}

#endif