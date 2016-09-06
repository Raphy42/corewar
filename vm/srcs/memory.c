//
// Created by Raphaël Dantzer on 29/08/16.
//

#include "../includes/vm.h"
#include "../includes/utils.h"

t_mem_offset        upload_champ_to_memory(t_vm_ram *ram, t_champion *champion, t_mem_offset cursor)
{
    t_mem_offset    i;

    i = 0;
    while (i < (int)champion->header->prog_size)
    {
        ram->memory[cursor + i] = champion->program[i];
        i++;
    }
    return (cursor + i);
}

void                memory_dump(t_vm *vm)
{
    int             i;
    int             champion;

    champion = 0;
    i = -1;
    while (++i < MEM_SIZE)
    {
        if (!(i % 64))
        {
            if (i)
                ft_putchar('\n');
            ft_putstr("0x");
            hex_print(i, 16, 4);
            ft_putstr(" : ");
        }
#if DEBUG
        if (vm->cores[champion].pc + (int)vm->champions[champion]->header->prog_size < i)
            champion += champion == vm->stats.champion_count - 1 ? 0 : 1;
        else if (vm->cores[champion].pc > i)
            ;
        else
        {
            if (i == vm->cores[champion].pc)
                ft_fprintf(1, "\033[%dm", 47);
            ft_fprintf(1, "\033[%dm", 31 + champion);
        }
#endif
        hex_print(vm->ram.memory[i], 16, 2);
#if DEBUG
        ft_putstr("\033[0m\033[0m");
#endif
        ft_putchar(0x20);
    }
    ft_putchar('\n');
}