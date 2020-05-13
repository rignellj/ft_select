/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:38:34 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 21:31:45 by jrignell         ###   ########.fr       */
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
# define ENTER 0xD
# define ESC 0x1B
# define DEL 0x7E335B1B
# define SPACE 0x20
# define BSPACE 0x7F

/*
********************************************************************************
**                         DEV                                                **
********************************************************************************
*/
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
	int			ws_rows;
	int			ws_cols;
	char		**av;
	char		**env;
	t_list		*head;
	t_termios	original_config;
	t_termios	rawmode;
}				t_sh;

typedef struct	s_args
{
	char		*name;
	t_bool		is_picked;
	t_bool		cursor;
}				t_args;

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
**                                                                            **
**                         MOST IMPORTANT FUNCTIONS                           **
**                                                                            **
********************************************************************************
*/

int				ft_putint_fd(int c);
void			se_clear_screen(void);
void			se_init(t_sh *t, int ac, char **av, char **env);
void			se_put_args_linkedlist(t_sh *t);
void			se_print_arg_stderr(t_sh *t);


int				se_readkey(void);
void			se_process_input(t_sh *t);
void			se_print_options_stdout(t_sh *t);
void			se_config(t_sh *t);
void			se_close(t_sh *t);
void			se_exit(char const *error);

#endif
