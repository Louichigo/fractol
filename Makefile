# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 09:17:29 by lobertho          #+#    #+#              #
#    Updated: 2024/09/29 17:59:49 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c keys.c colors.c mandelbrot.c julia.c ft_strcmp.c burningship.c utils.c ft_atof.c

OBJS = $(SRCS:.c=.o)

PRINTF = ./printf/libftprintf.a

CC =  gcc -Wall -Wextra -Werror

FLAGS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
		make -C mlx
		$(CC) -I./mlx -Lmlx -lmlx $(FLAGS) $(MLX) $(PRINTF) -o $(NAME) $(OBJS)

clean:
		make clean -C mlx
		rm -f $(OBJS)
	
fclean: clean
		rm -f $(NAME)
	
re: fclean all