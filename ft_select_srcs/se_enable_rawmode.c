/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_enable_rawmode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:11:14 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/12 18:44:58 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

/*
********************************************************************************
** '~' is for not, ICANON sets raw mode on, ISIG turn off Ctrl-C and Ctrl-Z   **
**                                                                            **
** IXON turn off Ctrl-S and Ctrl-Q, IEXTEN turn off Ctrl-V and Ctrl-O         **
**                                                                            **
** ICRNL turn off Ctrl-M and reads Enter as value 13                          **
**                                                                            **
** You can read more about BRKINT, INPCK, ISTRIP and CS8 on                   **
** https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html          **
**                                                                            **
** VMIN is for 'how many bytes you want to be read before read() returns      **
**                                                                            **
** VTIME is for maximum time to wait before read() returns                    **
********************************************************************************
*/

void	se_enable_rawmode(t_sh *t)
{
	if (tcgetattr(t->fd, &t->original_config) == -1)
		se_exit("tcgetattr: failed to get current state. Exiting..\r\n");
	t->rawmode = t->original_config;
	t->rawmode.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN);
	t->rawmode.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
	t->rawmode.c_oflag &= ~(OPOST);
	t->rawmode.c_cflag |= (CS8);
	t->rawmode.c_cc[VMIN] = 1;
	t->rawmode.c_cc[VTIME] = 0;
	if (tcsetattr(t->fd, TCSANOW, &t->rawmode) == -1)
		se_exit("tcsetattr: failed to make requested changes. Exiting..\r\n");
	tputs(tgetstr("vi", NULL), t->fd, ft_putint_fd);
	tputs(tgetstr("ti", NULL), t->fd, ft_putint_fd);
}
