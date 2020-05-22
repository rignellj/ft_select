/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_get_current_cursor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:26:33 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:02:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
