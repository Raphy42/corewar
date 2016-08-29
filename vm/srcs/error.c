//
// Created by Raphaël Dantzer on 25/07/16.
//

#include <sys/errno.h>
#include <stdio.h>
#include "../../libft/includes/libft.h"

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