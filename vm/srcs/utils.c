//
// Created by Raphaël Dantzer on 20/08/16.
//

#include <unistd.h>
#include "../includes/error.h"
#include "../includes/utils.h"
#include "../libft/includes/libft.h"

ssize_t     read_file_r(int fd, off_t start, size_t size, unsigned char *s)
{
    ssize_t len;
    off_t   cursor;

    if ((cursor = lseek(fd, start, SEEK_SET)) == -1)
        error_log("Unable to seek offset");
    if ((len = read(fd, s, size)) == -1)
        error_log("IO error");
    return (len);
}

ssize_t     read_file(int fd, size_t size, unsigned char *s)
{
    ssize_t len;

    if ((len = read(fd, s, size)) == -1)
        error_log("IO error");
    return (len);
}

t_uint      word_to_uint(unsigned char *w)
{
    t_uint  word;
    int     i;

    i = -1;
    word = 0;
    while (++i < (int)sizeof(unsigned int))
        word = (word << 8) + w[i];
    return (word);
}

void        hex_print(int n, int base, int precision)
{
    const char  *c_base = ITOA_BASE;

    if (n < base)
    {
        while (--precision > 0)
            ft_putchar(c_base[0]);
        ft_putchar(c_base[n]);
    }
    else
    {
        hex_print(n / base, base, --precision);
        ft_putchar(c_base[(n % base)]);
    }
}
