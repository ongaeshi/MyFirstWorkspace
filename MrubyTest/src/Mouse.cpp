#include "Mouse.hpp"

namespace rubybasic {
//------------------------------------------------------------
Mouse::Mouse()
: mX(0)
, mY(0)
, mButton(0)
{
}

//------------------------------------------------------------
void Mouse::update(int aX, int aY, int aButton)
{
    mX      = aX;
    mY      = aY;
    mButton = aButton;
}

}
