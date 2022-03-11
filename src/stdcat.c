#include "stdcat.h"


uint8_t cat_echo = true;


static int echo_write(const struct cat_variable *var, size_t write_size)
{
    assert(var != NULL);
    assert(write_size == 1);

    // remember previous value to reset on invalid input
    static uint8_t prev_cat_echo = true;

    // boolean-like must be 0 or 1
    if (cat_echo > 1) {
        cat_echo = prev_cat_echo;
        return CAT_RETURN_STATE_ERROR;
    }

    prev_cat_echo = cat_echo;

    return CAT_RETURN_STATE_DATA_OK;
}


struct cat_variable echo_vars[] = {
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
        .var = echo_vars,
        .var_num = sizeof(echo_vars) / sizeof(echo_vars[0]),
    },
    {
        .name = "E",
        .description = "Whether to echo commands back to the sender",
        .var = echo_vars,
        .var_num = sizeof(echo_vars) / sizeof(echo_vars[0]),
    }
};


struct cat_command_group std_cmd_group = {
    .cmd = std_cmds,
    .cmd_num = sizeof(std_cmds) / sizeof(std_cmds[0]),
};