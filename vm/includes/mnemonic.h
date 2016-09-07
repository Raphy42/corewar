//
// Created by Raphaël Dantzer on 19/08/16.
//

#ifndef COREWAR_MNEMONIC_H
#define COREWAR_MNEMONIC_H

#include "vm.h"

typedef enum    e_mnemonic
{
    LIVE = 0x01,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF
}               t_mnemonic;

int         op_live(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_ld(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_st(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_add(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_sub(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_and(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_or(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_xor(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_zjmp(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_ldi(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_zjmp(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_ldi(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_sti(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_fork(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_lld(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_lldi(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_lfork(t_vm_cpu *cpu, t_vm_ram *ram);
int         op_aff(t_vm_cpu *cpu, t_vm_ram *ram);


#endif //COREWAR_MNEMONIC_H
