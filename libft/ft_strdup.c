/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:21:50 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/04 18:03:09 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	if (!s1)
		return (NULL);
	if (!(dup = ft_strnew(ft_strlen(s1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		dup[i] = s1[i];
	dup[i] = '\0';
	return (dup);
}
