/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:08:52 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/03 12:13:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_arraydup(const char **tab)
{
	size_t	i;
	char	**ret;

	if (!tab)
		return (NULL);
	i = ft_arraylen((const void **)tab);
	if (!(ret = (char**)malloc(sizeof(*ret) * (i + 1))))
		return (NULL);
	ret[i] = NULL;
	while (i--)
	{
		ret[i] = ft_strdup(tab[i]);
	}
	return (ret);
}
