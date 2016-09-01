//
// Created by Raphaël Dantzer on 25/07/16.
//

#include "../includes/error.h"

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

void        usage(void)
{
    if (errno)
        perror("corewar");
    else
        ft_fprintf(2, "usage: ./corewar file.cor file2.cor\n");
    exit(EXIT_FAILURE);
}