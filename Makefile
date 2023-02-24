# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 23:15:46 by arcarval          #+#    #+#              #
#    Updated: 2023/02/23 20:52:52 by arcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK	=	\033[0;30m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
MAGENTA	=	\033[1;35m
ORANGE	=	\033[1;38;5;214m
RED		=	\033[0;31m
RESET	=	\033[0m
WHITE	=	\033[0;37m
YELLOW	=	\033[0;33m

# MINITALK
NAME			=	minitalk.a
LIBFT			=	./Libft/libft.a
HEADER			=	minitalk.h
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

SERVER			=	server
SERVER_SRC		=	$(SERVER).c
CLIENT			=	client
CLIENT_SRC		=	$(CLIENT).c
MINITALK_SRC	=	$(SERVER_SRC) $(CLIENT_SRC)
MINITALK_OBJS	=	$(MINITALK_SRC:.c=)

AR				=	ar -rcs
RM				=	rm -rf

% : %.c
			@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) $(CFLAGS) -o $(<:.c=) $< $(LIBFT)

$(NAME):	libft $(MINITALK_OBJS)

libft: 
			@cd ./Libft && make

all:		$(NAME)

clean:
			@$(RM) $(MINITALK_OBJS) $(SERVER) $(CLIENT)
			@echo "$(CYAN) MINITALK - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@cd ./Libft && make fclean
			@echo "$(CYAN) MINITALK - Bath is so good!  Now it's over. 🧼✨$(RESET)"

re:			fclean all

.PHONY:	all minitalk bonus clean fclean re
