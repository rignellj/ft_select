/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:38:34 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:00:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/printf_srcs/includes/ft_printf.h"
# include <termios.h>

/*
********************************************************************************
**                         KEYS                                               **
********************************************************************************
*/

# define LEFT 0x445B1B
# define RIGHT 0x435B1B
# define DOWN 0x425B1B
# define UP 0x415B1B
# define ENTER 0xA
# define ESC 0x1B
# define DEL 0x7E335B1B
# define SPACE 0x20
# define BSPACE 0x7F
# define ASTERISK 0x2A
# define MINUS 0x2D

/*
********************************************************************************
**                         STRUCTS                                            **
********************************************************************************
*/

typedef struct	termios	t_termios;

typedef struct	s_select
{
	int			ac;
	int			fd;
	int			key;
	int			rows;
	int			ws_rows;
	int			ws_cols;
	char		**av;
	t_list		*head;
	size_t		width;
	size_t		num_of_nodes;
	t_termios	original_config;
	t_termios	rawmode;
}				t_sh;

typedef struct	s_args
{
	char		*name;
	t_bool		is_picked;
	t_bool		cursor;
	t_bool		printed;
}				t_args;

/*
********************************************************************************
**                         GLOBALS                                            **
********************************************************************************
*/

t_sh			*g_select;

/*
********************************************************************************
**                         RAWMODE                                            **
********************************************************************************
*/

void			se_enable_rawmode(t_sh *t);
void			se_disable_rawmode(t_sh *t);

/*
********************************************************************************
**                         MODIFY LIST                                        **
********************************************************************************
*/

t_list			*se_get_current_cursor(t_sh *t);
int				se_move_cursor_modifylist(t_sh *t);
int				se_select_unselect(t_sh *t);
int				se_remove_link(t_sh *t);
void			se_del_memory(void *content, size_t content_size);

/*
********************************************************************************
**                         INITIALIZE FUNCTIONS                               **
********************************************************************************
*/

int				ft_putint_fd(int c);
void			se_init(t_sh *t, int ac, char **av);
void			se_put_args_linkedlist(t_sh *t);

/*
********************************************************************************
**                  INPUT / OUTPUT / USER BEHAVIOUR FUNCTIONS                 **
********************************************************************************
*/

void			se_clear_screen(void);
void			se_process_input(t_sh *t);
void			se_print_arg_stderr(t_sh *t);
void			se_def_how_to_print_and_print(t_sh *t, t_list *head);

/*
********************************************************************************
**                         SIGNALS                                            **
** 				Only function that needs globals                              **
********************************************************************************
*/

void			se_init_signal_handlers(void);

/*
********************************************************************************
**                         CLOSING                                            **
********************************************************************************
*/

void			se_print_options_stdout(t_sh *t);
void			se_close(t_sh *t);
void			se_exit(char const *error);

#endif
