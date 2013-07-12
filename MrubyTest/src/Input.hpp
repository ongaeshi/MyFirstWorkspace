#pragma once

#include "Mouse.hpp"

//--------------------------------------------------------------------------------
namespace rubybasic {

class Input {
public:
    Input();

    void update();

    Mouse& mouse() { return mMouse; }
    const Mouse& mouse() const { return mMouse; }

private:
    Mouse mMouse;
};

}
