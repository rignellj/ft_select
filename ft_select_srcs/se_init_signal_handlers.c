/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_init_signal_handlers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:55:10 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:28:47 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>
#include <sys/ioctl.h>

static void	se_signal_handler(int signum)
{
	if (signum == SIGTSTP)
	{
		se_disable_rawmode(g_select);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	else if (signum == SIGCONT)
	{
		se_enable_rawmode(g_select);
		se_init_signal_handlers();
		se_clear_screen();
		se_print_arg_stderr(g_select);
	}
	else if (signum == SIGWINCH)
	{
		se_print_arg_stderr(g_select);
	}
	else if (signum == SIGINT || signum == SIGABRT || signum == SIGIOT || signum
		== SIGSTOP || signum == SIGKILL || signum == SIGQUIT)
	{
		se_disable_rawmode(g_select);
		se_close(g_select);
	}
}

void		se_init_signal_handlers(void)
{
	signal(SIGTSTP, se_signal_handler);
	signal(SIGINT, se_signal_handler);
	signal(SIGABRT, se_signal_handler);
	signal(SIGIOT, se_signal_handler);
	signal(SIGSTOP, se_signal_handler);
	signal(SIGKILL, se_signal_handler);
	signal(SIGQUIT, se_signal_handler);
	signal(SIGCONT, se_signal_handler);
	signal(SIGWINCH, se_signal_handler);
}
