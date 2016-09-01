//
// Created by Raphaël Dantzer on 25/07/16.
//

#include <stdio.h>
#include "../includes/mnemonic.h"
#include "../includes/parse.h"
#include "../../libft/includes/libft.h"
#include "../includes/utils.h"
#include "../includes/vm.h"

int    main(int argc, char **argv)
{
    t_vm            *vm = init_vm(argc, argv);

    memory_dump(&vm->ram);
    return (0);
}