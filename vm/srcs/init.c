//
// Created by Raphaël Dantzer on 20/08/16.
//

#include "../includes/utils.h"
#include "../includes/vm.h"

t_vm        *init_vm(void)
{
    t_vm    *vm;

    vm = COR_CALLOC(t_vm);
    vm->ram.memory = COR_CALLOC_S(unsigned char, MEM_SIZE);
    return (vm);
}