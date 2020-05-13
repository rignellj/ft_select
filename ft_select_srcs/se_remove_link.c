/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_remove_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:39:40 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 18:23:15 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	se_del_memory(void *content, size_t content_size)
{
	t_args	*tmp;

	tmp = (t_args *)content;
	ft_strdel(&tmp->name);
	ft_memdel((void **)&tmp);
	content_size = 0;
}

int		se_remove_link(t_sh *t)
{
	t_list	*current;

	if (!(current = se_get_current_cursor(t)))
		return (0);
	if (current->prev && current->next)
	{
		((t_args *)current->prev->content)->cursor = TRUE;
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	else if (current->prev)
	{
		((t_args *)current->prev->content)->cursor = TRUE;
		current->prev->next = NULL;
	}
	else if (current->next)
	{
		t->head = current->next;
		((t_args *)current->next->content)->cursor = TRUE;
		current->next->prev = NULL;
	}
	else
		return (0);
	ft_lstdelone(&current, se_del_memory);
	return (1);
}
