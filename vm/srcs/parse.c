//
// Created by Raphaël Dantzer on 19/08/16.
//

#include <sys/fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "error.h"
#include "parse.h"
#include "utils.h"
#include "libft.h"

static int     file_check_header(int fd)
{
    int             magic;
    unsigned char   m[4];

    magic = 0;
    read_file(fd, 4, m);
    magic = word_to_uint(m);
    return (magic == COREWAR_EXEC_MAGIC ? 1 : 0);
}

static int      file_open(const char *filename)
{
    int             fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_log("Unable to open file");
    return (fd);
}

static void     file_move_cursor(int fd, off_t size, int whence)
{
    if (lseek(fd, size, whence) == -1)
        error_log("lseek error");
}

static t_header *file_get_header(int fd)
{
    t_header    *header;
    unsigned char   m[4];

    header = COR_CALLOC(t_header);
    read_file(fd, PROG_NAME_LENGTH, (unsigned char *)header->prog_name);
    file_move_cursor(fd, 8 + PROG_NAME_LENGTH, SEEK_SET);
    read_file(fd, sizeof(unsigned int), m);
    read_file(fd, COMMENT_LENGTH, (unsigned char *)header->comment);
    header->prog_size = word_to_uint(m);
    if (header->prog_size > CHAMP_MAX_SIZE)
        error_log("champion exceed maximum size");
    return (header);
}

t_champion   *file_get_champion(const char *filename)
{
    t_champion      *champion;
    int             fd;

    fd = file_open(filename);
    if (!file_check_header(fd))
    {
        errno = EBADEXEC;
        error_log(filename);
    }
    champion = COR_CALLOC(t_champion);
    champion->header = file_get_header(fd);
    file_move_cursor(fd, sizeof(t_header), SEEK_SET);
    read_file(fd, CHAMP_MAX_SIZE, champion->program);
    close(fd);
    return (champion);
}




