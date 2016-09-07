//
// Created by Raphaël Dantzer on 20/08/16.
//

#include "error.h"
#include "vm.h"
#include "utils.h"

static int  g_pid;

static int  check_next_number_arg(int argc, char **argv, int pos, const char *error)
{
    if (pos + 1 > argc || !ft_isdigit(argv[pos + 1][0]))
    {
        ft_fprintf(2, "options: %s\n", error);
        usage();
    }
    return (ft_atoi(argv[pos + 1]));
}

static int  set_vm_flag(int argc, char **argv, int pos, t_vm *vm)
{
    if (STR_EQUAL(argv[pos] + 1, "dump"))
        vm->stats.dump_interval = check_next_number_arg(argc, argv, pos, "invalid dump interval");
    else if (STR_EQUAL(argv[pos] + 1, "n"))
        g_pid = check_next_number_arg(argc, argv, pos, "invalid process id");
    else
    {
        ft_fprintf(2, "illegal option: %s\n", argv[pos]);
        usage();
    }
    return (1);
}

static void add_champion(char *filename, t_vm *vm)
{
    vm->champions[vm->stats.champion_count] = file_get_champion(filename);
    vm->cores[vm->stats.champion_count].pid = g_pid++;
    vm->stats.champion_count++;
    if (vm->stats.champion_count > MAX_PLAYERS)
    {
        errno = ENOMEM;
        error_log("too many champions: [1-4]");
    }
}

int         parse_vm_options(int argc, char **argv, t_vm *vm)
{
    int     i;

    i = 0;
    if (argc == 1)
        usage();
    while (++i < argc)
    {
        if (argv[i][0] == '-')
            i += set_vm_flag(argc, argv, i, vm);
        else
            add_champion(argv[i], vm);
    }
    return (0);
}