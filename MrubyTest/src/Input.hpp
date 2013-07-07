#pragma once

#include "Mouse.hpp"

//--------------------------------------------------------------------------------
namespace rubybasic {

class Input {
public:
    Input();

    void updateMouse(int aX, int aY, int aButton);
    const Mouse& mouse() const;

private:
    Mouse mMouse;
};

}
