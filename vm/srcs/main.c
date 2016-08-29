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
    (void)argc;
    t_champion      *c;
    t_vm            *vm = init_vm();

    c = file_get_champion(argv[1]);
    printf("name: '%s'\nsize: %d\ncomment: '%s'\n",
           c->header->prog_name,
           c->header->prog_size,
           c->header->comment);
    upload_champ_to_memory(&vm->ram, c, 0);
    memory_dump(&vm->ram);
    return (0);
}