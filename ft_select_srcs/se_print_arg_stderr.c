/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_arg_stderr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:50:47 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 15:30:38 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

static void	se_print_selected(t_list *current)
{
	char	*name;
	int		cursor;
	int		is_selected;

	name = ((t_args *)current->content)->name;
	cursor = ((t_args *)current->content)->cursor;
	is_selected = ((t_args *)current->content)->is_picked;
	if (cursor && is_selected)
		ft_dprintf(STDERR_FILENO, CULINEDREVV"%s%s\r\n", name, CRESET);
	else if (is_selected)
		ft_dprintf(STDERR_FILENO, CREVERSEVIDEO"%s%s\r\n", name, CRESET);
	else if (cursor)
		ft_dprintf(STDERR_FILENO, CUNDERLINED"%s%s\r\n", name, CRESET);
	else
		ft_dprintf(STDERR_FILENO, "%s\r\n", name);
}

void		se_print_arg_stderr(t_sh *t)
{
	t_list	*current;

	current = t->head;
	while (current)
	{
		se_print_selected(current);
		// tputs(tgetstr("cl", NULL), 1, ft_putint_fd);
		current = current->next;
	}
}
// tputs(tgetstr("ve", NULL), 1, ft_putint_fd);
	// tputs(tgetstr("te", NULL), 1, ft_putint_fd);