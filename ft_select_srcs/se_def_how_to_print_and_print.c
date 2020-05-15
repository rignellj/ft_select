/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_def_how_to_print_and_print.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 14:50:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/15 20:47:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>///

static size_t	se_strmaxlen(t_list *head, size_t *nodes)
{
	size_t	len;
	size_t	l;
	t_list	*current;

	current = head;
	len = 0;
	*nodes = 0;
	while (current)
	{
		if ((l = ft_strlen(((t_args *)current->content)->name)) > len)
			len = l;
		current = current->next;
		(*nodes)++;
	}
	return (++len);
}

static void		se_print(t_list *current, size_t num_spaces)
{	
	char	*name;
	t_bool	cursor;
	t_bool	is_selected;

	name = ((t_args *)current->content)->name;
	cursor = ((t_args *)current->content)->cursor;
	is_selected = ((t_args *)current->content)->is_picked;
	((t_args *)current->content)->printed = TRUE;
	if (cursor && is_selected)
		ft_dprintf(STDERR_FILENO, CULINEDREVV"%-*s%s", num_spaces, name, CRESET);
	else if (is_selected)
		ft_dprintf(STDERR_FILENO, CREVERSEVIDEO"%-*s%s", num_spaces, name, CRESET);
	else if (cursor)
		ft_dprintf(STDERR_FILENO, CUNDERLINED"%-*s%s", num_spaces, name, CRESET);
	else
		ft_dprintf(STDERR_FILENO, "%-*s", num_spaces, name);
}

static void		se_print_current(t_list *head, size_t r, size_t l)
{
	size_t	skip;
	t_list	*current;
	// size_t	num_spaces;

	// num_spaces = l - ft_strlen(((t_args *)head->content)->name);
	se_print(head, l);
	// exit(1);
	current = head;
	while (current)
	{
		skip = r;
		while (current && skip--)
			current = current->next;
		if (current)
		{
			// num_spaces = l - ft_strlen(((t_args *)current->content)->name);
			se_print(current, l);
		}
	}
	ft_dprintf(STDERR_FILENO, "\r\n");
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
	size_t	max_len;
	size_t	num_of_nodes;
	size_t	rows;
	size_t	pages;

	max_len = se_strmaxlen(t->head, &num_of_nodes);
	// ft_printf("max len: %d numofNodes: %d\r\n", max_len, num_of_nodes);
	t->ws_cols /= max_len;
	// ft_printf("cols: %d\n", t->ws_cols);
	t->ws_cols += t->ws_cols == 0 ? 1 : 0;
	rows = (num_of_nodes / t->ws_cols) + 1;
	pages = t->ws_rows / rows + 1;
	se_print_current(head, rows, max_len);
}
