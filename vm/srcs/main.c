//
// Created by Raphaël Dantzer on 25/07/16.
//

#include <stdio.h>
#include "mnemonic.h"
#include "parse.h"
#include "libft.h"
#include "utils.h"
#include "vm.h"
#include "loop.h"

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