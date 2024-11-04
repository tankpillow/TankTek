#include <TankTek/math/Vec2f.hpp>

namespace TankTek
{
    Vec2f::Vec2f() : x(0), y(0)
    {}

    Vec2f::Vec2f(Vec2f& vec) : x(vec.x), y(vec.y)
    {}

    Vec2f::Vec2f(float x, float y) : x(x), y(y)
    {}
}