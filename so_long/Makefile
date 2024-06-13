# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:48:26 by mehakcan          #+#    #+#              #
#    Updated: 2024/06/03 12:30:46 by mehakcan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc -g
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-Lft_printf -Llibft -Lminilibx -lftprintf -lft -lmlx -framework OpenGL -framework AppKit
SOURCES =	src/chars_control.c		\
			src/exit.c 				\
			src/get_next_line.c		\
			src/mobilize.c			\
			src/main.c				\
			src/map_control.c		\
			src/mlx_create.c		\
			src/play_map_control.c


OBJ = $(SOURCES:.c=.o)

all		:	$(NAME)

$(NAME)	:	mdir $(OBJ)
		$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

mdir	:
		@make -C ft_printf
		@make -C libft
		@make -C minilibx

clean	:
		@make -C ft_printf	clean
		@make -C libft 		clean
		@make -C minilibx	clean
		@rm -f $(OBJ)

fclean :
		@make -C ft_printf	fclean
		@make -C libft 		fclean
		@make -C minilibx	clean
		@rm	-f $(NAME) $(OBJ)

re		:	fclean all

.PHONY	:	all $(NAME) mdir clean fclean re
.SECONDARY: mlx
