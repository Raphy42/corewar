//
// Created by Raphaël Dantzer on 20/07/16.
//

#ifndef COREWAR_VM_H
#define COREWAR_VM_H

#include "op.h"

/**
 * https://en.wikipedia.org/wiki/Opaque_data_type
 */
typedef int         t_register;
typedef int         t_flag;

typedef struct      s_vm
{
    t_register      registers[REG_NUMBER];
    t_register      pc;
    t_flag          flag;
}                   t_vm;

#endif //COREWAR_VM_H
