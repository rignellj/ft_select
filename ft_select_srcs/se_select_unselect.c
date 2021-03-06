/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_select_unselect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:21:04 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 16:20:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	se_select_all(t_list *elem)
{
	((t_args *)elem->content)->is_picked = TRUE;
}

static void	se_unselect_all(t_list *elem)
{
	((t_args *)elem->content)->is_picked = FALSE;
}

static int	se_select_unselect_all(t_sh *t)
{
	if (t->key == MINUS)
		ft_lstiter(t->head, se_unselect_all);
	else if (t->key == ASTERISK)
		ft_lstiter(t->head, se_select_all);
	t->key = 0;
	return (1);
}

int			se_select_unselect(t_sh *t)
{
	t_list	*current;
	t_bool	*is_selected;

	if (t->key != SPACE)
		return (se_select_unselect_all(t));
	if (!(current = se_get_current_cursor(t)))
		se_exit("There was an error finding cursor position. Exiting...\r\n");
	is_selected = &((t_args *)current->content)->is_picked;
	if (*is_selected == FALSE)
		*is_selected = TRUE;
	else if (*is_selected == TRUE)
		*is_selected = FALSE;
	t->key = 0;
	return (1);
}
