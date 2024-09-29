# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:37:42 by lobertho          #+#    #+#              #
#    Updated: 2022/11/14 12:16:56 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_hexamaj.c ft_hexamin.c ft_int.c ft_pointeur.c ft_printf.c ft_string.c ft_unsint.c ft_putchar.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all