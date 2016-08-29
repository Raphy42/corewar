//
// Created by Raphaël Dantzer on 20/07/16.
//

#ifndef COREWAR_OP_H
#define COREWAR_OP_H

# define IND_SIZE           2
# define REG_SIZE           4
# define DIR_SIZE           REG_SIZE

# define REG_CODE           1
# define DIR_CODE           2
# define IND_CODE           3

# define MAX_ARGS_NUMBER    4
# define MAX_PLAYERS        4
# define MEM_SIZE           (4 * 1024)
# define IDX_MOD            (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE     (MEM_SIZE / 6)

# define REG_NUMBER         16
# define CYCLE_TO_DIE       1536
# define CYCLE_DELTA        50
# define NBR_LIVE           21
# define MAX_CHECKS         10

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

#endif //COREWAR_OP_H
