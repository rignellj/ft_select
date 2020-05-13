/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:42:36 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/12 14:34:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

void	se_exit(char const *error)
{
	char	*str;

	se_clear_screen();
	str = ft_strdup(error);
	ft_dprintf(STDERR_FILENO, "%s", str);
	ft_strdel(&str);
	exit(EXIT_FAILURE);
}
