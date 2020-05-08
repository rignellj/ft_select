/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraystr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:06:14 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/04 20:15:51 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arraystr(const char **tab, const char *s)
{
	size_t	i;
	size_t	len;
	char	**arr;
	char	*str;

	str = (char *)s;
	arr = (char **)tab;
	i = 0;
	len = ft_strlen(str);
	while (arr && arr[i] && str)
	{
		if (ft_strncmp(arr[i], str, len) == 0)
			return (arr[i]);
		i++;
	}
	return (NULL);
}
