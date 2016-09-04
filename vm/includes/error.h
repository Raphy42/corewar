//
// Created by Raphaël Dantzer on 19/08/16.
//

#ifndef COREWAR_ERROR_H
#define COREWAR_ERROR_H

#include <sys/errno.h>
#include <stdio.h>
#include "../../libft/includes/libft.h"

typedef enum    e_corewar_errno
{
    COR_EBADSIZE = 0x0,
    COR_EOP
}               t_corewar_errno;

void        error_log(const char *error);
void        usage(void);
void        corewar_exception(t_corewar_errno err);

#endif //COREWAR_ERROR_H
