# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 15:47:48 by hankhali          #+#    #+#              #
#    Updated: 2023/11/02 16:44:18 by hankhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = events.c init.c fractol.c math_utils.c render.c string_utils.c events2.c fractolrender.c julia.c

OBJ = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re