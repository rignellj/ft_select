/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:39:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 13:21:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	se_close(t_sh *t)
{
	t_list	*current;

	while (t->head)
	{
		current = t->head->next;
		ft_memdel((void **)&((t_args *)t->head->content)->name);
		ft_memdel((void **)&(t->head->content));
		ft_memdel((void **)&(t->head));
		t->head = current;
	}
	close(t->fd);
}
