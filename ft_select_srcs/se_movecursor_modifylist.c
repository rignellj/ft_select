/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_movecursor_modifylist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:24:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 16:26:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*se_move_to_next_column(t_list *current, t_sh *t)
{
	t_list	*tmp;

	tmp = current;
	if (t->key == RIGHT)
	{
		while (current && t->rows--)
			current = current->next;
		if (!current)
			return (ft_lstget_first(tmp));
	}
	else if (t->key == LEFT)
	{
		while (current && t->rows--)
			current = current->prev;
		if (!current)
			return (ft_lstget_last(tmp));
	}
	return (current);
}

static t_list	*se_move_cursor(t_list *current, t_sh *t)
{
	t_list	*tmp;

	tmp = current;
	((t_args *)current->content)->cursor = FALSE;
	if (t->key == RIGHT || t->key == LEFT)
		return (se_move_to_next_column(current, t));
	if (t->key == DOWN)
	{
		if (!(current = current->next))
			return (ft_lstget_first(tmp));
	}
	else if (t->key == UP)
	{
		if (!(current = current->prev))
			return (ft_lstget_last(tmp));
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
