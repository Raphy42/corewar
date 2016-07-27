# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdantzer <rdantzer@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 14:02:08 by rdantzer          #+#    #+#              #
#    Updated: 2016/07/25 14:02:08 by rdantzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= corewar

SRC= $(shell find "srcs" -type f -print | grep "\.c")

OBJ= $(SRC:.c=.o)
CC= /usr/bin/gcc
CFLAGS= -Wall -Wextra -Werror -g -I ./includes/ -I ./libft/includes/
RM= /bin/rm -f
LIB= libft

$(NAME): $(OBJ)
    @make -C $(LIB)
    @$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB) -lft && \
    printf "                                                                   \r" && \
    printf "\033[0;32m\033[1m   %-28s\033[0m -->>\t\033[1m\033[32m[%s]\033[0;0m\n" \
    "Compiling..." "$@"

clean:
@make clean -C $(LIB)
@$(RM) $(OBJ)

fclean: clean
@make fclean -C $(LIB)
@$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY: re all clean fclean

.c.o:
    @$(CC) $(CFLAGS) -o $@ -c $< \
    && (printf "\r \033[0;0m%-30s\033[1;30m -->>\t\033[0;31m$@\033[0;0m" "$<" \
    && printf "            \r") \
    || (printf "\033[0;0m%-30s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
            && exit 1)
