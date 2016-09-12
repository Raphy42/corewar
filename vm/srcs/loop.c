//
// Created by Raphaël Dantzer on 25/07/16.
//

#include "loop.h"
#include "vm.h"

static void process_loop(t_vm_cpu *cpu, t_vm_ram *ram)
{
    if (cpu->busy)
        cpu->busy--;
    else
        decode(cpu, ram);
}

int         game_loop(t_vm *vm)
{
    int     champ;

    champ = -1;
    while (++champ < vm->stats.champion_count)
        process_loop(&vm->cores[champ], &vm->ram);
    return (1);
}