/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:25:22 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/12 16:03:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>

static void	se_print_usage(t_sh *t)
{
	if (t->ac < 1)
	{
		se_exit("usage: <command> `./ft_select [arg1, ...]`\r\n");
	}
}

static int	se_get_windowsize(t_sh *t)
{
	struct winsize w;

	if (ioctl(t->fd, TIOCGWINSZ, &w) == -1 || w.ws_col == 0)
		return (-1);
	t->ws_cols = w.ws_col;
	t->ws_rows = w.ws_row;
	return (0);
}

void		se_init(t_sh *t, int ac, char **av, char **env)
{
	t->ac = --ac;
	t->av = ++av;
	t->env = env;
	se_print_usage(t);
	if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY | O_NOCTTY)) < 0)
		return (se_exit("Failed to open port\r\n"));
	if (se_get_windowsize(t) == -1)
		se_exit("ioctl: failed to get current window state. Exiting..\r\n");
}
