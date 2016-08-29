//
// Created by Raphaël Dantzer on 19/08/16.
//

#ifndef COREWAR_FILE_H
#define COREWAR_FILE_H

#include "vm.h"

typedef struct      s_header
{
    unsigned int    magic;
    char            prog_name[PROG_NAME_LENGTH + 1];
    unsigned int    prog_size;
    char            comment[COMMENT_LENGTH + 1];
}                   t_header;

typedef struct      s_champion
{
    t_header        *header;
    unsigned char   program[CHAMP_MAX_SIZE + 1];
}                   t_champion;

/**
 * parse.c
 */
t_champion * file_get_champion(const char *filename);

#endif //COREWAR_FILE_H
