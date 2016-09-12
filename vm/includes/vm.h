//
// Created by Raphaël Dantzer on 20/07/16.
//

#ifndef COREWAR_VM_H
#define COREWAR_VM_H

#include "op.h"
#include "parse.h"
#include "libft.h"

#define DEBUG   1

//TODO fix circular reference
typedef struct s_champion   t_champion;

/**
 * https://en.wikipedia.org/wiki/Opaque_data_type
 */
typedef int         t_register;
typedef int         t_flag;
typedef int         t_mem_offset;
typedef int         t_cycle;

typedef struct      s_vm_ram
{
    unsigned char   *memory;
}                   t_vm_ram;

typedef struct      s_vm_cpu
{
    t_register      registers[REG_NUMBER];
    t_register      pc;
    t_flag          flag;
    int             pid;
    t_cycle         busy;
}                   t_vm_cpu;

typedef struct      s_vm_stats
{
    t_cycle         cycles;
    t_cycle         cycle_to_die;
    t_cycle         lives;
    t_cycle         dump_interval;
    int             champion_count;
}                   t_vm_stats;

typedef struct      s_vm
{
    t_vm_ram        ram;
    t_vm_cpu        cores[MAX_PLAYERS];
    t_vm_stats      stats;
    t_champion      *champions[MAX_PLAYERS];
}                   t_vm;


/**
 * memory.c
 */
t_mem_offset        upload_champ_to_memory(t_vm_ram *ram, t_champion *champion, t_mem_offset cursor);
void                memory_dump(t_vm *vm);

/**
 * init.c
 */
t_vm                *init_vm(int argc, char **argv);

/**
 * loop.c
 */
int                 game_loop(t_vm *vm);

#endif //COREWAR_VM_H
