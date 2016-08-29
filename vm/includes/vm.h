//
// Created by Raphaël Dantzer on 20/07/16.
//

#ifndef COREWAR_VM_H
#define COREWAR_VM_H

#include "op.h"
#include "parse.h"
#include "../libft/includes/libft.h"

/**
 * https://en.wikipedia.org/wiki/Opaque_data_type
 */
typedef int         t_register;
typedef int         t_flag;
typedef int         t_mem_offset;

typedef struct      s_vm_ram
{
    unsigned char   *memory;
}                   t_vm_ram;

typedef struct      s_vm_cpu
{
    t_register      registers[REG_NUMBER];
    t_register      pc;
    t_flag          flag;
}                   t_vm_cpu;

typedef struct      s_vm
{
    t_vm_ram        ram;
    t_vm_cpu        *cores;
}                   t_vm;

//TODO fix circular reference
typedef struct s_champion   t_champion;

/**
 * memory.c
 */
t_mem_offset        upload_champ_to_memory(t_vm_ram *ram, t_champion *champion, t_mem_offset cursor);
void                memory_dump(t_vm_ram *ram);

/**
 * init.c
 */
t_vm                *init_vm(void);

#endif //COREWAR_VM_H
