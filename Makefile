# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/03/09 19:13:21 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf

CC			= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra -g

SRC 		= 	main.c ft_dot_struct.c ft_max_xy.c\
				ft_link_roots.c ft_place_dots.c \
				rot_0d/ft_link_one_1.c rot_0d/ft_link_two_1.c \
				rot_90d/ft_link_one_2.c rot_90d/ft_link_two_2.c \
				rot_180d/ft_link_one_3.c rot_180d/ft_link_two_3.c \
				rot_270d/ft_link_one_4.c rot_270d/ft_link_two_4.c \
				ft_tools.c ft_help.c

LIB			=	-Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL \
				-framework AppKit

OBJ			=	main.o ft_dot_struct.o ft_max_xy.o\
				ft_link_roots.o ft_place_dots.o \
				ft_link_one_1.o ft_link_two_1.o \
				ft_link_one_2.o ft_link_two_2.o \
				ft_link_one_3.o ft_link_two_3.o \
				ft_link_one_4.o ft_link_two_4.o \
				ft_tools.o ft_help.o

HEADER 		=	libft/libft.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	cd libft/ && $(MAKE) re
	cd minilibx_macos/ && $(MAKE) re
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	cd libft/ && $(MAKE) clean
	cd minilibx_macos/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch
	rm -rf *.dSYM

.SILENT : fclean
fclean: clean
	cd libft/ && $(MAKE) fclean
	cd minilibx_macos/ && $(MAKE) clean
	rm -f $(NAME)

re: fclean all
