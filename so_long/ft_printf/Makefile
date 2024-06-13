# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:40:33 by mehakcan          #+#    #+#              #
#    Updated: 2024/01/16 15:40:33 by mehakcan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf

SRC		= ft_printf.c \
		  ft_printf_utils.c

OBJ		= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ) $(B_OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re