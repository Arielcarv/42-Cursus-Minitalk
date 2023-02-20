# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 16:00:05 by arcarval          #+#    #+#              #
#    Updated: 2023/02/19 16:02:04 by arcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Minitalk.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	server.c	client.c

OBJS		=	$(SRCS:.c=.o)

BONUS		=	server_bonus.c	client_bonus.c

BONUS_OBJS	=	$(BONUS:.c=.o)

AR			=	ar -rcs

RM			=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) libft.h
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(NAME) $(BONUS_OBJS)
			$(AR) $(NAME) $(BONUS_OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME) libft.so a.out

re:			fclean all

.PHONY:	all bonus clean fclean re