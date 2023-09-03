# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 16:05:11 by alexandrine       #+#    #+#              #
#    Updated: 2023/09/03 16:05:38 by alexandrine      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	pipex.c\
		utils.c\
		libft/libft.a\

SRCS_BONUS = 	bonus/pipex_bonus.c\
				bonus/utils_bonus.c\
				libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)