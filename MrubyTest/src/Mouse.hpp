#pragma once

//------------------------------------------------------------
namespace rubybasic {
class Mouse {
public:
    static const int L_BUTTON = 0;
    static const int M_BUTTON = 1;
    static const int R_BUTTON = 2;
    
    Mouse();

    void setInternalPos(int aX, int aY);
    
    void update();

    int x() const { return mX; }
    int y() const { return mY; }

private:
    struct Internal {
        Internal()
        : x(0)
        , y(0)
        , button(0) {}
            
        int x;
        int y;
        int button;
    };

    Internal mInternal;
    int mX;
    int mY;
};

}
