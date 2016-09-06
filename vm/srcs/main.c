//
// Created by Raphaël Dantzer on 25/07/16.
//

#include <stdio.h>
#include "../includes/mnemonic.h"
#include "../includes/parse.h"
#include "../../libft/includes/libft.h"
#include "../includes/utils.h"
#include "../includes/vm.h"
#include "../includes/loop.h"

int    main(int argc, char **argv)
{
    t_vm            *vm = init_vm(argc, argv);

    memory_dump(vm);
    for (int i = 0; i < 8; i++)
    {
        decode(&vm->cores[0], &vm->ram);
        ft_putchar('\n');
    }
    return (0);
}