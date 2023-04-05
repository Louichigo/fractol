# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 09:17:29 by lobertho          #+#    #+#              #
#    Updated: 2023/03/02 13:51:16 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c keys.c colors.c mandelbrot.c julia.c ft_strcmp.c burningship.c utils.c ft_atof.c

OBJS = $(SRCS:.c=.o)

PRINTF = ./printf/libftprintf.a

CC =  gcc -Wall -Wextra -Werror

FLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -I./mlx -Lmlx -lmlx $(FLAGS) $(PRINTF) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
	
fclean: clean
		rm -f $(NAME)
	
re: fclean all