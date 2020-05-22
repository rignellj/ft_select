/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:39:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:29:56 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

void	se_close(t_sh *t)
{
	t->original_config.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(t->fd, TCSANOW, &t->original_config) == -1)
		se_exit("tcsetattr: failed to make requested changes. Exiting..\n");
	if (t->head)
		ft_lstdel(&t->head, se_del_memory);
	close(t->fd);
	exit(EXIT_SUCCESS);
}
