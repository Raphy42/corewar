//
// Created by Raphaël Dantzer on 19/08/16.
//

#ifndef COREWAR_UTILS_H
#define COREWAR_UTILS_H

#include <unistd.h>

#ifndef ITOA_BASE
# define ITOA_BASE      "0123456789abcedefghijklmnopqrstuvwxyz"
#endif

# define COR_CALLOC(x)          (x *)ft_memalloc(sizeof(x))
# define COR_CALLOC_S(x, s)     (x *)ft_memalloc(sizeof(x) * s)
# define COR_MALLOC(x)          (x *)malloc(sizeof(x))

typedef unsigned int        t_uint;

ssize_t     read_file_r(int fd, off_t start, size_t size, unsigned char *s);
ssize_t     read_file(int fd, size_t size, unsigned char *s);
t_uint      word_to_uint(unsigned char *w);
void        hex_print(int n, int base);

#endif //COREWAR_UTILS_H
