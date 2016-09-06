//
// Created by Raphaël Dantzer on 04/09/16.
//

#include "../includes/vm.h"
#include "../includes/error.h"
#include "../includes/utils.h"
#include "../includes/decode.h"

t_op	g_opt_tab[17] =
        {
                {0, 0, {T_NONE, T_NONE, T_NONE}, 0, 0, 0, -1},
                {"live", 1, {T_DIR, T_NONE, T_NONE}, 1, 10, 0, 4},
                {"ld", 2, {T_DIR | T_IND, T_REG, T_NONE}, 2, 5, 1, 4},
                {"st", 2, {T_REG, T_IND | T_REG, T_NONE}, 3, 5, 1, 0},
                {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0},
                {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0},
                {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 4},
                {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 4},
                {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 4},
                {"zjmp", 1, {T_DIR, T_NONE, T_NONE}, 9, 20, 0, 2},
                {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 2},
                {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 2},
                {"fork", 1, {T_DIR, T_NONE, T_NONE}, 12, 800, 0, 2},
                {"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, 1, 4},
                {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 2},
                {"lfork", 1, {T_DIR, T_NONE, T_NONE}, 15, 1000, 0, 2},
                {"aff", 1, {T_REG, T_NONE, T_NONE}, 16, 2, 1, 0}
        };

/**
 * Decode OPC
 * return argument count + 1 (opc)
 */
static int          get_args(int byte)
{
    int             args;
    int             shift;

    args = 0;
    shift = 8;
    while (shift-= 2)
        args += (byte >> shift) & 3;
    return (args);
}

static void         memdump(t_vm_ram *ram, int pc, int count)
{
    int             i;

    i = -1;
    while (++i < count)
    {
        hex_print(ram->memory[pc + i], 16, 2);
        ft_putchar(0x20);
    }
}

//TODO omg
void                decode(t_vm_cpu *cpu, t_vm_ram *ram)
{
    unsigned char   word;
    int             args;

    args = 0;
    word = ram->memory[cpu->pc];
    /**
     * Check for illegal opcode ?
     */
    if (word > 0x10 || word == 0)
        corewar_exception(COR_EOP);
    ft_putstr("0x");
    hex_print(cpu->pc, 16, 2);
    ft_putstr(g_opt_tab[word].mnemonique);
    args = get_args(ram->memory[cpu->pc]);
    memdump(ram, cpu->pc, args);
    cpu->pc += args + (g_opt_tab[word].code_oct ? 1 : 0);
//    ft_putstr("0x");
//    hex_print(cpu->pc, 16, 2);
//    ft_putchar('\n');
}
