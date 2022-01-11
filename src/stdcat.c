#include "stdcat.h"


uint8_t cat_echo = false;


static int echo_write(const struct cat_variable *var, size_t write_size)
{
    assert(var != NULL);
    assert(write_size == 1);

    // clamp values between 0 and 1
    if (cat_echo > 1) {
        cat_echo = 1;
    }

    return 0;
}


struct cat_variable std_vars[] = {
    {
        .type = CAT_VAR_UINT_DEC,
        .data = &cat_echo,
        .data_size = sizeof(cat_echo),
        .name = "ECHO",
        .write = echo_write
    }
};


struct cat_command std_cmds[] = {
    {
        .name = "+E",
        .description = "Whether to echo commands back to the sender",
        .var = std_vars,
        .var_num = sizeof(std_vars) / sizeof(std_vars[0]),
    }
};


struct cat_command_group std_cmd_group = {
    .cmd = std_cmds,
    .cmd_num = sizeof(std_cmds) / sizeof(std_cmds[0]),
};