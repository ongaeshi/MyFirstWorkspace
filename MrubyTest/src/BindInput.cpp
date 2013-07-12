#include "BindInput.hpp"

#include "Input.hpp"
#include "mruby.h"
#include "ofAppRunner.h"

namespace rubybasic {
namespace {
    Input* sInput = NULL;

    static mrb_value input_mouse_x(mrb_state *mrb, mrb_value self)
    {
        return mrb_fixnum_value(sInput->mouse().x());
    }

    static mrb_value input_mouse_y(mrb_state *mrb, mrb_value self)
    {
        return mrb_fixnum_value(sInput->mouse().y());
    }
}

//--------------------------------------------------------------------------------
void BindInput::Setup(Input& aInput)
{
    sInput = &aInput;
}

//--------------------------------------------------------------------------------
void BindInput::Bind(mrb_state* mrb)
{
    struct RClass* c = mrb_define_module(mrb, "Input");

    mrb_define_module_function(mrb, c, "mouse_x", input_mouse_x, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, c, "mouse_y", input_mouse_y, MRB_ARGS_NONE());
}

}

//EOF
