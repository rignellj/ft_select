/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_def_how_to_print_and_print.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 14:50:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:01:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		se_print(t_list *current, size_t width)
{
	char	*name;
	t_bool	cursor;
	t_bool	is_selected;

	name = ((t_args *)current->content)->name;
	cursor = ((t_args *)current->content)->cursor;
	is_selected = ((t_args *)current->content)->is_picked;
	((t_args *)current->content)->printed = TRUE;
	if (cursor && is_selected)
		ft_dprintf(STDERR_FILENO, "%s%-*s%s", CULINEDREVV, width, name, CRESET);
	else if (is_selected)
		ft_dprintf(STDERR_FILENO, "%s%-*s%s",
		CREVERSEVIDEO, width, name, CRESET);
	else if (cursor)
		ft_dprintf(STDERR_FILENO, "%s%-*s%s", CUNDERLINED, width, name, CRESET);
	else
		ft_dprintf(STDERR_FILENO, "%-*s", width, name);
}

static void		se_print_current(t_list *head, size_t r, size_t width, size_t p)
{
	size_t	skip;
	t_list	*current;

	se_print(head, width);
	current = head;
	while (current)
	{
		skip = r;
		while (current && skip--)
			current = current->next;
		if (current)
			se_print(current, width);
	}
	p = 0;//
	ft_dprintf(STDERR_FILENO, "\n");
}

/*
********************************************************************************
** t->ws_cols = num of files per one row                                      **
** rows = how many rows files take overall                                    **
** num_of_nodes = how many files need to be printed                           **
** pages = how many screens do files take when all of them are being printed  **
********************************************************************************
*/

void			se_def_how_to_print_and_print(t_sh *t, t_list *head)
{
	size_t	rows;
	size_t	pages;

	t->ws_cols /= t->width;
	if (t->ws_cols == 0)
		t->ws_cols = 1;
	rows = (t->num_of_nodes / t->ws_cols) + 1;
	t->rows = rows;
	pages = (rows / t->ws_rows) + 1;
	se_print_current(head, rows, t->width, pages);
}
