#include "MRuby.hpp"

#include "mruby/class.h"
#include "mruby/compile.h"

namespace rubybasic {

//--------------------------------------------------------------------------------
MRuby::MRuby(const char* aFilename)
: mFilename(aFilename)
, mMrb(mrb_open())
{
    FILE *fd = fopen(mFilename, "r");
    mrb_load_file(mMrb, fd);
    fclose(fd);
}

//--------------------------------------------------------------------------------
MRuby::~MRuby()
{
    if (mMrb)
        mrb_close(mMrb);
}

//--------------------------------------------------------------------------------
mrb_value MRuby::funcallIf(const char* aName)
{
    if (mMrb && isExistFunction(kernel_obj(), aName)) {
        mrb_value value = mrb_funcall(mMrb, kernel_obj(), aName, 0);
        closeOnException();
        return value;
    }

    return mrb_nil_value();
}

//--------------------------------------------------------------------------------
mrb_value MRuby::funcallIf(const char* aName, mrb_value aArg1, mrb_value aArg2, mrb_value aArg3)
{
    if (mMrb && isExistFunction(kernel_obj(), aName)) {
        mrb_value value = mrb_funcall(mMrb, kernel_obj(), aName, 3, aArg1, aArg2, aArg3);
        closeOnException();
        return value;
    }

    return mrb_nil_value();
}

//--------------------------------------------------------------------------------
bool MRuby::isExistFunction(mrb_value aSelf, const char* aFuncName)
{
    struct RClass *c = mrb_class(mMrb, aSelf);
    struct RProc *p = mrb_method_search_vm(mMrb, &c, mrb_intern(mMrb, aFuncName));
    return p != NULL;
}

//--------------------------------------------------------------------------------
void MRuby::closeOnException()
{
    if (mMrb->exc) {
        mrb_p(mMrb, mrb_obj_value(mMrb->exc));
        mrb_close(mMrb);
        mMrb = NULL;
    }
}


}
