//
// Created by Raphaël Dantzer on 25/07/16.
//

#include "loop.h"
#include "vm.h"

static void process_loop(t_vm_cpu *cpu, t_vm_ram *ram)
{
    if (cpu->busy)
        cpu->busy--;
    else if (cpu->op)
        fetch(cpu, ram);
    else
        decode(cpu, ram);
}

int         game_loop(t_vm *vm)
{
    int     champ;

    while (vm->stats.cycles < 110)
    {
        champ = -1;
        ft_fprintf(2, "cycle :%d\n", vm->stats.cycles);
        while (++champ < vm->stats.champion_count)
            process_loop(&vm->cores[champ], &vm->ram);
        vm->stats.cycles++;
    }
    return (1);
}