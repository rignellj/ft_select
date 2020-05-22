/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_disable_rawmode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:42:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 15:57:59 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	se_disable_rawmode(t_sh *t)
{
	if (tcsetattr(t->fd, TCSANOW, &t->original_config) == -1)
		se_exit("tcsetattr: failed to make requested changes. Exiting..\n");
	tputs(tgetstr("ve", NULL), 1, ft_putint_fd);
	tputs(tgetstr("te", NULL), 1, ft_putint_fd);
}
