//
// Created by Raphaël Dantzer on 20/08/16.
//

#include "../includes/utils.h"
#include "../includes/vm.h"
#include "../includes/error.h"
#include "../includes/options.h"


static void init_game(t_vm *vm)
{
    int                 i;
    const t_mem_offset  cursor = MEM_SIZE / vm->stats.champion_count;

    i = -1;
    while (++i < vm->stats.champion_count)
    {
        ft_fprintf(2, "champion: '%s'\ncomment: '%s'\nsize: '%d'\npid: %d\n\n",
                   vm->champions[i]->header->prog_name,
                   vm->champions[i]->header->comment,
                   vm->champions[i]->header->prog_size,
                   vm->cores[i].pid);
        upload_champ_to_memory(&vm->ram, vm->champions[i], cursor * i);
        vm->cores[i].pc = cursor * i;
    }
}

t_vm        *init_vm(int argc, char **argv)
{
    t_vm    *vm;

    vm = COR_CALLOC(t_vm);
    parse_vm_options(argc, argv, vm);
    vm->ram.memory = COR_CALLOC_S(unsigned char, MEM_SIZE);
    init_game(vm);
    return (vm);
}
