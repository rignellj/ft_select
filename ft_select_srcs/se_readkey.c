/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_readkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:38:36 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/16 12:27:42 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		se_readkey(void)
{
	int		key;

	key = 0;
	if (read(STDERR_FILENO, &key, 4) == -1)
		se_exit("read: failed to read STDERR. Exiting..\n");
	ft_dprintf(STDERR_FILENO, "%d ('%c')\r\n", key, key);
	return (key);
}
