/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_options_stdout.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:20:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:05:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	se_print_options_stdout(t_sh *t)
{
	size_t	i;
	t_list	*current;

	i = 0;
	current = t->head;
	while (current)
	{
		if (((t_args *)current->content)->is_picked)
			ft_dprintf(STDOUT_FILENO, "%s ",
			((t_args *)current->content)->name);
		current = current->next;
	}
}
