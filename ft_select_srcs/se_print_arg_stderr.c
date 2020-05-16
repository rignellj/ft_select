/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_arg_stderr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:50:47 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/16 12:39:05 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>
#include <sys/ioctl.h>

static void	se_not_printed(t_list *elem)
{
	((t_args *)elem->content)->printed = FALSE;
}

static int	se_get_windowsize(t_sh *t)
{
	struct winsize w;

	if (ioctl(t->fd, TIOCGWINSZ, &w) == -1 || w.ws_col == 0)
		return (-1);
	t->ws_cols = w.ws_col;
	t->ws_rows = w.ws_row;
	return (0);
}

void		se_print_arg_stderr(t_sh *t)
{
	t_list	*current;

	current = t->head;
	while (current)
	{
		if (se_get_windowsize(t) == -1)
			se_exit("ioctl: failed to get current window state. Exiting..\r\n");
		if (((t_args *)current->content)->printed == FALSE)
			se_def_how_to_print_and_print(t, current);
		current = current->next;
	}
	ft_lstiter(t->head, se_not_printed);
}
// tputs(tgetstr("ve", NULL), 1, ft_putint_fd);
	// tputs(tgetstr("te", NULL), 1, ft_putint_fd);