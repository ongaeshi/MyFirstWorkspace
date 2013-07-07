#pragma once

//------------------------------------------------------------
namespace rubybasic {
class Mouse {
public:
    Mouse();

    void update(int aX, int aY, int aButton);

    int x() const { return mX; }
    int y() const { return mY; }
    int button() const { return mButton; }

private:
    int mX;
    int mY;
    int mButton;
};

}
