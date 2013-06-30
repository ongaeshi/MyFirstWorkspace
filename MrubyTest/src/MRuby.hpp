#pragma once

#include "mruby.h"

//--------------------------------------------------------------------------------
namespace rubybasic {

class MRuby {
public:
    MRuby(const char* aFilename);
    ~MRuby();

    mrb_state* mrb() { return mMrb; }

    mrb_value funcallIf(mrb_value aSelf, const char* aName);

    void reload();

private:
    bool isExistFunction(const char* aFuncName);
    bool closeOnException();

    const char* mFilename;
    mrb_state*  mMrb;
};

}
