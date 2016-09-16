#include "vm.h"

int        op_sti(t_vm_cpu *cpu, t_vm_ram *ram)
{
    get_args(ram->memory[cpu->pc + 1], cpu);

    return (0);
}