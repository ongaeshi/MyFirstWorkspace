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
mrb_value MRuby::funcallIf(mrb_value aSelf, const char* aName)
{
    if (isExistFunction("setup")) {
        mrb_funcall(mMrb, aSelf, aName, 0);
        closeOnException();
    }
}

//--------------------------------------------------------------------------------
bool MRuby::isExistFunction(const char* aFuncName)
{
    mrb_value value = mrb_obj_value(mMrb->kernel_module);
    struct RClass *c = mrb_class(mMrb, value);
    struct RProc *p = mrb_method_search_vm(mMrb, &c, mrb_intern(mMrb, aFuncName));
    return p != NULL;
}

//--------------------------------------------------------------------------------
bool MRuby::closeOnException()
{
    if (mMrb->exc) {
        mrb_p(mMrb, mrb_obj_value(mMrb->exc));
        mrb_close(mMrb);
        mMrb = NULL;
    }
}


}
