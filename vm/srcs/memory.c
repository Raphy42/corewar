//
// Created by Raphaël Dantzer on 29/08/16.
//

#include <stdio.h>
#include "../includes/vm.h"
#include "../../libft/includes/libft.h"
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

void                memory_dump(t_vm_ram *ram)
{
    int             i;

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
        hex_print(ram->memory[i], 16, 2);
        ft_putchar(0x20);
    }
    ft_putchar('\n');
}