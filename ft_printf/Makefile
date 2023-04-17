# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 08:21:59 by dbaldoni          #+#    #+#              #
#    Updated: 2023/02/28 00:32:16 by dbaldoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c ft_hex.c ft_dec.c ft_point.c\

OBJS			= $(SRCS:.c=.o)



CC				= gcc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C libft
				cp libft/libft.a ./$(NAME)
				#gcc  $(OBJS) -o $(NAME) libft/libft.a 
				ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re 