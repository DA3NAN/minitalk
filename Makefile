# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 20:54:54 by aait-mal          #+#    #+#              #
#    Updated: 2022/12/21 14:17:07 by aait-mal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c
LIBFT = libft_dir
PRINTF = ft_printf_dir

CC = cc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : libft printf client server

libft : $(LIBFT)/libft.h
	@echo "\033[0;34mMaking libft...\033[m"
	@cd $(LIBFT) && make bonus && mv libft.a ..

printf :
	@echo "\033[0;34mMaking ft_printf...\033[m"
	@cd $(PRINTF) && make && mv libftprintf.a ..

client : $(SRC_CLIENT) minitalk.h
	@echo "Making exec 'client'..."
	@cc $(FLAGS) $(SRC_CLIENT) libft.a libftprintf.a -o client

server : $(SRC_SERVER) minitalk.h
	@echo "Making exec 'server'..."
	@cc $(FLAGS) $(SRC_SERVER) libft.a libftprintf.a -o server

bonus : all client_bonus server_bonus

client_bonus : $(SRC_CLIENT_BONUS) minitalk.h
	@echo "Making exec 'client' for bonus..."
	@cc $(FLAGS) $(SRC_CLIENT_BONUS) libft.a libftprintf.a -o client_bonus

server_bonus : $(SRC_SERVER_BONUS) minitalk.h
	@echo "Making exec 'server' for bonus..."
	@cc $(FLAGS) $(SRC_SERVER_BONUS) libft.a libftprintf.a -o server_bonus

clean :
	@echo "\033[0;31mCleaning...\033[m"
	@cd $(LIBFT) && make clean
	@cd $(PRINTF) && make clean

fclean : clean
	@echo "\033[0;31mDeleting executables...\033[m"
	@rm -f client server client_bonus server_bonus libft.a libftprintf.a

re : fclean all
