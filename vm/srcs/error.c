//
// Created by Raphaël Dantzer on 25/07/16.
//

#include "../includes/error.h"

const char *cor_char_code[] = {
        "champion size mismatch",
        "illegal opcode"
};

void        error_log(const char *error)
{
    if (errno)
    {
        perror(error);
        exit(EXIT_FAILURE);
    }
    else
        ft_fprintf(2, "%s: %s: %d\n", error, __FILE__, __LINE__);
}

void        corewar_exception(t_corewar_errno err)
{
    ft_fprintf(2, "fatal error: %s\n", cor_char_code[err]);
    exit(EXIT_FAILURE);
}

void        usage(void)
{
    if (errno)
        perror("corewar");
    else
        ft_fprintf(2, "usage: ./corewar file.cor file2.cor\n");
    exit(EXIT_FAILURE);
}