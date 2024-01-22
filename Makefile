# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 12:20:37 by ablondel          #+#    #+#              #
#    Updated: 2021/07/19 18:54:46 by ablondel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
pixels.c \
events.c \
args.c \
setup.c \
sets.c

OBJ = ${SRC:.c=.o}

NAME = fractol

$(NAME):		$(OBJ)
		$(CC) -lmlx -framework AppKit -framework OpenGL libmlx.a $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re