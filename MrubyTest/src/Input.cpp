#include "Input.hpp"

namespace rubybasic {
//------------------------------------------------------------
Input::Input()
: mMouse()
{
}

//------------------------------------------------------------
void Input::updateMouse(int aX, int aY, int aButton)
{
    mMouse.update(aX, aY, aButton);
}

//------------------------------------------------------------
const Mouse& Input::mouse() const
{
    return mMouse;
}

}
