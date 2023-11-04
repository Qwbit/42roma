# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 19:51:24 by dbaldoni          #+#    #+#              #
#    Updated: 2023/11/04 17:04:48 by dbaldoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = Main.c Hook.c Math.c Render.c Select.c \

OBJECTS = $(SOURCES:.c=.o)

CC = gcc -g -fsanitize=address 
CFLAGS = -Wall -Werror -Wextra

all: fractol

fractol: $(OBJECTS) libmlx libft
	$(CC) Main.c Hook.c Math.c Render.c Select.c -g -o fractol $(CFLAGS) -I./ -Lminilibx-linux -lmlx -Llibft -lft -lX11 -lXext -lm


%.o: %.c 
		$(CC) -c $(CFLAGS) $?

libft:
		make -C libft/ && cp libft/libft.a ..

libmlx:
		make -C minilibx-linux/ && cp minilibx-linux/libmlx.a ..

clean:
		rm -f $(OBJECTS) fractol
		make -C libft clean


fclean: clean
		rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re