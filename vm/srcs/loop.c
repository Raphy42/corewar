//
// Created by Raphaël Dantzer on 25/07/16.
//

#include "../includes/vm.h"

const char              *op_name[] = {
        "live",
        "ld",
        "st",
        "add",
        "sub",
        "and",
        "or",
        "xor",
        "zjmp",
        "ldi",
        "sti",
        "fork",
        "lld",
        "lldi",
        "aff"
};

unsigned char           loop_fetch(t_vm_cpu *cpu, t_vm_ram *ram)
{
    const unsigned char word = ram->memory[cpu->pc];

    ft_putstr(op_name[word]);
    return (word);
}


