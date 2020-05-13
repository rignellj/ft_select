/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:35:09 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 21:23:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>
#include <stdlib.h>

static int	se_process_keypress(t_sh *t)
{
	while ((t->key = se_readkey()))
	{
		if (t->key == ENTER)
			break ;
		else if (t->key == SPACE)
			return (se_select_unselect(t));
		else if (t->key == DEL || t->key == BSPACE || t->key == ESC)
			return (se_remove_link(t));
		else
			return (se_move_cursor_modifylist(t));
	}
	return (0);
}
/*
	// else if (t->key == UP)
		// 	ft_dprintf(STDERR_FILENO, "this is up arrow\r\n");
		// else if (t->key == DOWN)
		// 	//ft_dprintf(STDERR_FILENO, "this is down arrow\r\n");
		// else if (t->key == LEFT)
		// 	ft_dprintf(STDERR_FILENO, "this is left arrow\r\n");
		// else if (t->key == RIGHT)
		// 	ft_dprintf(STDERR_FILENO, "this is right arrow\r\n");
*/
void	se_process_input(t_sh *t)
{
	int		status;

	status = 1;
	while (status)
	{
		se_clear_screen();
		se_print_arg_stderr(t);
		status = se_process_keypress(t);
	}
}
