/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:29:57 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/10 14:07:25 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	se_config(t_sh *t)
{
	// if (tcgetattr(t->fd, &t->old_config) < 0)
	// 	return (se_exit("Failure\n"));
	if (!ft_arraystr((const char **)t->env, "TERM"))
		return (se_exit("No environment variable TERM\n"));
	if (!isatty(t->fd))
		return (se_exit("File descriptor is not pointing to TTY device\n"));
	
}
