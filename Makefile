# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 18:19:52 by jrignell          #+#    #+#              #
#    Updated: 2020/05/08 19:07:16 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRC_DIR := ./ft_select_srcs
OBJ_DIR := ./obj

SRC :=	main.c
		
OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@/bin/mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/printf_srcs/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/printf_srcs/libftprintf.a -ltermcap

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/printf_srcs/ clean
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@make -C libft/printf_srcs/ fclean
	@make -C libft/ fclean
	
ft: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/printf_srcs/libftprintf.a -ltermcap
	@make clean

re: fclean all

.PHONY: all clean re fclean