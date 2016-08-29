//
// Created by Raphaël Dantzer on 19/08/16.
//

#ifndef COREWAR_MNEMONIC_H
#define COREWAR_MNEMONIC_H

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



#endif //COREWAR_MNEMONIC_H
