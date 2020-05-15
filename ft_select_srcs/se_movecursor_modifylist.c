/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_movecursor_modifylist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:24:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 21:45:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*se_move_cursor(t_list *current, t_sh *t)
{
	t_list	*tmp;

	tmp = current;
	((t_args *)current->content)->cursor = FALSE;
	if (t->key == DOWN || t->key == RIGHT)
	{
		if (!(current = current->next))
			return (ft_lstget_first(tmp));
	}
	else if (t->key == UP || t->key == LEFT)
	{
		if (!(current = current->prev))
			return (ft_lstget_last(tmp));
	}
	return (current);
}

t_list			*se_get_current_cursor(t_sh *t)
{
	t_list	*current;

	current = t->head;
	while (current)
	{
		if (((t_args *)current->content)->cursor == TRUE)
			break ;
		current = current->next;
	}
	return (current);
}

int				se_move_cursor_modifylist(t_sh *t)
{
	t_list	*current;

	if (!(current = se_get_current_cursor(t)))
		se_exit("There was an error finding cursor position. Exiting...\r\n");
	current = se_move_cursor(current, t);
	((t_args *)current->content)->cursor = TRUE;
	t->key = 0;
	return (1);
}
