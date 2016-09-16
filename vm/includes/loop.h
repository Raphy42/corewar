//
// Created by Raphaël Dantzer on 04/09/16.
//

#ifndef COREWAR_LOOP_H
#define COREWAR_LOOP_H

#include "vm.h"

typedef struct      s_op_func
{
    int             (* op)(t_vm_cpu *, t_vm_ram *);
}                   t_op_func;

int                 decode(t_vm_cpu *cpu, t_vm_ram *ram);
int                 fetch(t_vm_cpu *cpu, t_vm_ram *ram);

#endif //COREWAR_LOOP_H
