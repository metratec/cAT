#include "cat_std.h"


bool echo = false;


static struct cat_variable std_vars[] = {
    {
        .type = CAT_VAR_UINT_DEC,
        .data = &echo,
        .data_size = sizeof(echo),
        .name = "ECHO",
        .access = CAT_VAR_ACCESS_READ_WRITE,
    }
};


/* run command handler with custom exit mechanism */
static int set_echo(const struct cat_command *cmd)
{
        printf("set echo");
        return 0;
}


static struct cat_command std_cmds[] = {
        {
                .name = "+E",
                .description = "Whether to echo commands back to the sender",
                .var = std_vars,
                .run = set_echo,
                .var_num = sizeof(std_vars) / sizeof(std_vars[0]),
        }
};


static struct cat_command_group std_cmd_group = {
        .cmd = std_cmds,
        .cmd_num = sizeof(std_cmds) / sizeof(std_cmds[0]),
};