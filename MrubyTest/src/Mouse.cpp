#include "Mouse.hpp"

namespace rubybasic {
//------------------------------------------------------------
Mouse::Mouse()
: mInternal()
, mX(0)
, mY(0)
{
}

//------------------------------------------------------------
void Mouse::setInternalPos(int aX, int aY)
{
    mInternal.x = aX;
    mInternal.y = aY;
}
 
//------------------------------------------------------------
void Mouse::update()
{
    mX = mInternal.x;
    mY = mInternal.y;
    // printf("x: %d, y: %d\n", mX, mY);
}

}
