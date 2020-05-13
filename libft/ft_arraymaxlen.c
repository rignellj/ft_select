/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymaxlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:57:22 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/11 21:05:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arraymaxlen(const char **tab)
{
	size_t	i;
	size_t	j;
	size_t	max;

	if (!tab)
		return (0);
	i = 0;
	max = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}
