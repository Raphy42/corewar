//
// Created by Raphaël Dantzer on 09/09/16.
//

#include <loop.h>
#include <mnemonic.h>
#include "vm.h"

t_op_func g_op_func[] = {
        {NULL},
        {&op_live},
        {&op_ld},
        {&op_st},
        {&op_add},
        {&op_sub},
        {&op_and},
        {&op_or},
        {&op_xor},
        {&op_zjmp},
        {&op_ldi},
        {&op_sti},
        {&op_fork},
        {&op_lld},
        {&op_lldi},
        {&op_lfork},
        {&op_aff}
};
//TODO implement function

int     fetch(t_vm_cpu *cpu, t_vm_ram *ram) {
    (void) cpu;
    (void) ram;
    return (g_op_func[cpu->op].op(cpu, ram));
}