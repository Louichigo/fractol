# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 13:12:41 by lobertho          #+#    #+#              #
#    Updated: 2023/02/18 15:21:42 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c keys.c colors.c mandelbrot.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

FLAGS = -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
		$(CC) -Imlx -Lmlx -lmlx $(FLAGS) -o $(NAME) $(OBJS)


all: $(NAME)

clean:
		rm -f $(OBJS)
	
fclean: clean
		rm -f $(NAME)
	
re: fclean all