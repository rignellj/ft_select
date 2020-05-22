/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:25:22 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:04:08 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <fcntl.h>
#include <stdlib.h>
#include <term.h>

static void	se_print_usage(t_sh *t)
{
	if (t->ac < 1)
	{
		se_exit("usage: <command> `./ft_select [arg1, ...]`\r\n");
	}
}

static void	se_valid_terminal(char *term_name)
{
	int		res;
	char	buf[2048];

	if (!isatty(STDERR_FILENO))
		se_exit("Not a terminal. Exiting..\n");
	if ((res = tgetent(buf, term_name)) < 1)
	{
		res == -1 ? se_exit("Could not access termcap data base. Exiting..\n")
		: se_exit("Terminal type not found\r\n. Exiting..\n");
	}
}

void		se_init(t_sh *t, int ac, char **av)
{
	char	*term_name;

	t->ac = --ac;
	t->av = ++av;
	g_select = t;
	se_print_usage(t);
	if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY | O_NOCTTY)) < 0)
		return (se_exit("Failed to open port\n"));
	if (!(term_name = getenv("TERM")))
		return
		(se_exit("Set a terminal type using `setenv TERM <type>`. Exiting.\n"));
	se_valid_terminal(term_name);
}
