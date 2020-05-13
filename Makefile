# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 18:19:52 by jrignell          #+#    #+#              #
#    Updated: 2020/05/13 21:35:45 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR := ./includes
SRC_DIR := ./ft_select_srcs
OBJ_DIR := ./obj

SRC :=	main.c \
		se_exit.c \
		se_init.c \
		se_close.c \
		se_config.c \
		se_readkey.c \
		se_del_memory.c \
		se_remove_link.c \
		se_clear_screen.c \
		se_process_input.c \
		se_enable_rawmode.c \
		se_disable_rawmode.c \
		se_select_unselect.c \
		se_print_arg_stderr.c \
		se_put_args_linkedlist.c \
		se_print_options_stdout.c \
		se_movecursor_modifylist.c

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@/bin/mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Building libft..."
	@make -C libft/printf_srcs/
	@echo "Building ft_select..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/printf_srcs/libftprintf.a -ltermcap
	@echo "DONE\n"
	@echo "usage: <command> \`./ft_select [arg1, ...]\`"

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/printf_srcs/ clean
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@make -C libft/printf_srcs/ fclean
	@make -C libft/ fclean
	
se: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/printf_srcs/libftprintf.a -ltermcap
	@make clean

re: fclean all

.PHONY: all clean re fclean