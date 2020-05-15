/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_select_unselect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:21:04 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 21:45:30 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		se_select_unselect(t_sh *t)
{
	t_list	*current;
	t_bool	*is_selected;

	if (!(current = se_get_current_cursor(t)))
		se_exit("There was an error finding cursor position. Exiting...\r\n");
	is_selected = &((t_args *)current->content)->is_picked;
	if (*is_selected == FALSE)
		*is_selected = TRUE;
	else
		*is_selected = FALSE;
	t->key = 0;
	return (1);
}
