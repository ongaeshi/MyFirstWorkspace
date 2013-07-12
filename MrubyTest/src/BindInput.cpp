#include "BindInput.hpp"

#include "mruby.h"
#include "ofAppRunner.h"

namespace {
    static mrb_value input_mouse(mrb_state *mrb, mrb_value self)
    {
        // return mrb_obj_value();
        return mrb_float_value(mrb, ofGetFrameRate());
    }
}

//--------------------------------------------------------------------------------
void BindInput::Bind(mrb_state* mrb)
{
    // struct RClass* c = mrb_define_class(mrb, "Input", mrb->object_class);
    // mrb_define_method(mrb, c, "mouse", input_mouse, MRB_ARGS_NONE());

    // struct RClass* c = mrb_define_class(mrb, "Mouse", mrb->object_class);
    // mrb_define_method(mrb, c, "x", input_mouse_x, MRB_ARGS_NONE());
    // mrb_define_method(mrb, c, "y", input_mouse_y, MRB_ARGS_NONE());
    // mrb_define_method(mrb, c, "button", input_mouse_button, MRB_ARGS_NONE());
}

//EOF
