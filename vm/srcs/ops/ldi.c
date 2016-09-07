#include "decode.h"

int        op_ldi(t_vm_cpu *cpu, t_vm_ram *ram)
{
    const int   args = get_args(ram->memory[cpu->pc + 1], ram->memory[cpu->pc]);

    (void)cpu; (void)ram;
    return (args + 1);
}