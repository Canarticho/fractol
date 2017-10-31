# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chle-van <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 19:42:37 by chle-van          #+#    #+#              #
#    Updated: 2017/10/29 23:05:44 by chle-van         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wextra -Werror -Wall -g
CLIB=-lmlx
CFRAMWORKS=-framework OpenGL -framework Appkit
NAME=fractol
LIBDIR=./libft/
LIBFT=$(LIBDIR)libft.a
INCLUDE_DIR=$(LIBDIR)includes
OBJ=$(SRC:.c=.o)
SRC=draw.c\
	events.c\
	fractol.c\
	fractal.c\
	fractal1.c\
	fractal2.c\

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) $(CFRAMWORKS) -o $@ $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

$(OBJ)%.o:$(SRC)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDE_DIR)

re:fclean all

clean:
	rm -rf $(OBJ)
	make -C $(LIBDIR) clean

fclean:clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
