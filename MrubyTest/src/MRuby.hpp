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
    mrb_value funcallIf(mrb_value aSelf, const char* aName, mrb_value aArg1);
    mrb_value funcallIf(mrb_value aSelf, const char* aName, mrb_value aArg1, mrb_value aArg2);
    mrb_value funcallIf(mrb_value aSelf, const char* aName, mrb_value aArg1, mrb_value aArg2, mrb_value aArg3);

    void reload();

private:
    bool isExistFunction(mrb_value aSelf, const char* aFuncName);
    bool closeOnException();

    const char* mFilename;
    mrb_state*  mMrb;
};

}
