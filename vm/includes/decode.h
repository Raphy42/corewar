//
// Created by Raphaël Dantzer on 05/09/16.
//

#ifndef COREWAR_DECODE_H
#define COREWAR_DECODE_H

#include "op.h"

typedef enum                e_arg_type
{
    T_NONE = 0x0,
    T_REG = 0x1,
    T_DIR = 0x2,
    T_IND = 0x4
}                           t_arg_type;

typedef struct				s_op
{
    char					*mnemonique;
    char					nbr_args;
    t_arg_type     		    type[MAX_ARGS_NUMBER];
    char					code;
    int						nbr_cycles;
    char					code_oct;
    int                     size;
}							t_op;

#endif //COREWAR_DECODE_H
