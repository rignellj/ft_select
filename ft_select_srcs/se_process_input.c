/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:35:09 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:04:48 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	se_readkey(void)
{
	int		key;

	key = 0;
	if (read(STDERR_FILENO, &key, 4) == -1)
		se_exit("read: failed to read STDERR. Exiting..\n");
	return (key);
}

static int	se_process_keypress(t_sh *t)
{
	while ((t->key = se_readkey()))
	{
		if (t->key == ENTER)
			break ;
		else if (t->key == SPACE || t->key == ASTERISK || t->key == MINUS)
			return (se_select_unselect(t));
		else if (t->key == DEL || t->key == BSPACE || t->key == ESC)
			return (se_remove_link(t));
		else
			return (se_move_cursor_modifylist(t));
	}
	return (0);
}

void		se_process_input(t_sh *t)
{
	int		status;

	status = 1;
	while (status)
	{
		se_clear_screen();
		se_print_arg_stderr(t);
		status = se_process_keypress(t);
	}
	se_clear_screen();
}
