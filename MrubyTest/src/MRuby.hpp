#pragma once

#include "mruby.h"

//--------------------------------------------------------------------------------
namespace rubybasic {

class MRuby {
public:
    MRuby(const char* aFilename);
    ~MRuby();

    mrb_state* mrb() { return mMrb; }

    // Create need function only 
    mrb_value funcallIf(const char* aName);
    mrb_value funcallIf(const char* aName, mrb_value aArg1, mrb_value aArg2, mrb_value aArg3);

    void reload();

private:
    struct RClass* kernel_module() { return mMrb->kernel_module; }
    mrb_value      kernel_obj()    { return mrb_obj_value(kernel_module()); }

    bool isExistFunction(mrb_value aSelf, const char* aFuncName);
    void closeOnException();

    const char* mFilename;
    mrb_state*  mMrb;
};

}
