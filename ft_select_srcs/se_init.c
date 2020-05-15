/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:25:22 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/15 14:31:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <fcntl.h>
// #include <stdlib.h>

static void	se_print_usage(t_sh *t)
{
	if (t->ac < 1)
	{
		se_exit("usage: <command> `./ft_select [arg1, ...]`\r\n");
	}
}

void		se_init(t_sh *t, int ac, char **av, char **env)
{
	t->ac = --ac;
	t->av = ++av;
	t->env = env;
	se_print_usage(t);
	if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY | O_NOCTTY)) < 0)
		return (se_exit("Failed to open port\r\n"));
}
