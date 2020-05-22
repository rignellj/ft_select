/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_remove_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:39:40 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:02:26 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	se_del_middle_link(t_list *current)
{
	((t_args *)current->prev->content)->cursor = TRUE;
	current->prev->next = current->next;
	current->next->prev = current->prev;
}

static void	se_del_last_link(t_list *current)
{
	((t_args *)current->prev->content)->cursor = TRUE;
	current->prev->next = NULL;
}

static void	se_del_first_link(t_list *current, t_sh *t)
{
	t->head = current->next;
	((t_args *)current->next->content)->cursor = TRUE;
	current->next->prev = NULL;
}

int			se_remove_link(t_sh *t)
{
	t_list	*current;

	if (!(current = se_get_current_cursor(t)))
		return (0);
	if (t->key == ESC)
	{
		ft_lstdel(&t->head, se_del_memory);
		return (0);
	}
	if (current->prev && current->next)
		se_del_middle_link(current);
	else if (current->prev)
		se_del_last_link(current);
	else if (current->next)
		se_del_first_link(current, t);
	else
		return (0);
	ft_lstdelone(&current, se_del_memory);
	t->key = 0;
	return (1);
}
