//
// Created by Raphaël Dantzer on 25/07/16.
//

#include "mnemonic.h"

int    main(int argc, char **argv)
{
    t_vm            *vm = init_vm(argc, argv);

    memory_dump(vm);
    game_loop(vm);
    return (0);
}