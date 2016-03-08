# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/03/08 19:12:19 by Tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fdf

CC		= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra

SRC 	= 	main.c ft_dot_struct.c ft_max_xy.c\
			ft_link_one_1.c ft_link_one_2.c ft_link_one_3.c ft_link_one_4.c \
			ft_link_two_1.c ft_link_two_2.c ft_link_two_3.c ft_link_two_4.c \
			ft_link_roots.c\
			ft_tools.c

LIB		=	-Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL \
			-framework AppKit

OBJ		=	$(SRC:.c=.o)

HEADER 	=	libft/libft.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	# cd libft/ && $(MAKE) re
	# cd minilibx_macos/ && $(MAKE) re
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	# cd libft/ && $(MAKE) clean
	# cd minilibx_macos/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch
	rm -rf *.dSYM

.SILENT : fclean
fclean: clean
	# cd libft/ && $(MAKE) fclean
	# cd minilibx_macos/ && $(MAKE) clean
	rm -f $(NAME)

re: fclean all
