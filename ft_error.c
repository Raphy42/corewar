//
// Created by jvolonda on 11/09/16.
//

#include "libft/includes/libft.h"

void    ft_error(char *error)
{
    if (error)
    {
        ft_fprintf(2, error);
    }
    exit(1);
}