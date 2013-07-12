#pragma once

//------------------------------------------------------------
namespace rubybasic {
class Mouse {
public:
    static const int L_BUTTON = 0;
    static const int M_BUTTON = 1;
    static const int R_BUTTON = 2;
    
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
