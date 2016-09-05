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

all:
		@make -C vm

clean:
		@make clean -C vm

fclean:		clean
		@make fclean -C $vm

re:		fclean all

.PHONY:		re all clean fclean