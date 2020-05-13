/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_options_stdout.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:20:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/12 17:44:53 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	se_print_options_stdout(t_sh *t)
{
	size_t	i;

	i = 0;
	while (t->av[i + 1])
	{
		ft_dprintf(STDERR_FILENO, "%s ", t->av[i]);
		i++;
	}
	ft_dprintf(STDERR_FILENO, "%s\n", t->av[i]);
}
