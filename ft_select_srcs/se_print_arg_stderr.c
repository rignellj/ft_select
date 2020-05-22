/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_arg_stderr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:50:47 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:04:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>
#include <sys/ioctl.h>

static void		se_not_printed(t_list *elem)
{
	((t_args *)elem->content)->printed = FALSE;
}

static size_t	se_strmaxlen(t_list *head, size_t *nodes)
{
	size_t	len;
	size_t	l;
	t_list	*current;

	current = head;
	len = 0;
	*nodes = 0;
	while (current)
	{
		if ((l = ft_strlen(((t_args *)current->content)->name)) > len)
			len = l;
		current = current->next;
		(*nodes)++;
	}
	return (++len);
}

static int		se_get_windowsize(t_sh *t, int i)
{
	struct winsize	w;

	t->width = se_strmaxlen(t->head, &t->num_of_nodes);
	while ((ioctl(t->fd, TIOCGWINSZ, &w)) != -1 && w.ws_col != 0)
	{
		if (w.ws_row >= 4 && w.ws_col >= t->width)
		{
			if (i == 0)
				se_clear_screen();
			t->ws_cols = w.ws_col;
			t->ws_rows = w.ws_row;
			return (0);
		}
		if (i == 1)
		{
			se_clear_screen();
			ft_dprintf(STDERR_FILENO, "%s", "Not enough space for items.\n");
			i = 0;
		}
	}
	return (-1);
}

void			se_print_arg_stderr(t_sh *t)
{
	t_list	*current;

	current = t->head;
	while (current)
	{
		if (se_get_windowsize(t, 1) == -1)
			se_exit("ioctl: failed to get current window state. Exiting..\n");
		if (((t_args *)current->content)->printed == FALSE)
			se_def_how_to_print_and_print(t, current);
		current = current->next;
	}
	ft_lstiter(t->head, se_not_printed);
}
