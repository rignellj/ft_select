/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:00:06 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/26 21:00:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_ptr_push(void const **src, void *ptr)
{
	void	**dst;
	void	**tmp;
	size_t	len;

	tmp = (void**)src;
	len = ft_arraylen(src);
	if (!(dst = (void**)ft_memalloc(sizeof(*dst) * (len + 2))))
		return (NULL);
	dst[len + 1] = NULL;
	dst[len] = ptr;
	while (len--)
	{
		dst[len] = tmp[len];
	}
	return (dst);
}
