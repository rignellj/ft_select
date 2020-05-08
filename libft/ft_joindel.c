/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joindel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:05:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/03 15:49:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_joindel(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	return (new);
}
