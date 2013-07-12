#pragma once

struct mrb_state;

//--------------------------------------------------------------------------------
class BindInput {
public:
    static void Bind(mrb_state* mrb);
};

//EOF

