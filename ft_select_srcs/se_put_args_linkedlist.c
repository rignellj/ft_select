/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_put_args_linkedlist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:03:05 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:02:59 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	se_create_list(t_list **node, char *name)
{
	t_list	*new;
	t_args	content;

	content.is_picked = FALSE;
	content.cursor = FALSE;
	content.printed = FALSE;
	if (!(content.name = ft_strdup(name)))
		se_exit("Malloc *** error\n");
	new = ft_lstnew(&content, sizeof(t_args));
	ft_lstappend(node, new);
}

void		se_put_args_linkedlist(t_sh *t)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = NULL;
	while (t->av[i])
	{
		se_create_list(&node, t->av[i]);
		i++;
	}
	t->head = node;
	((t_args *)t->head->content)->cursor = TRUE;
}
