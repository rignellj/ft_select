/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:28:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/23 14:55:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char c, const char *delims)
{
	size_t	i;

	i = 0;
	while (delims[i])
	{
		if (c == delims[i++])
			return (0);
	}
	return (-1);
}

static int	move_ptr(char **str, const char *delims)
{
	while (is_delim(**str, delims) != -1)
		(*str)++;
	return (1);
}

char		*ft_strtok(char *str, const char *delims)
{
	static char	*ptr;
	char		*token;

	if (str && move_ptr(&str, delims))
		ptr = str;
	if (!ptr)
		return (NULL);
	token = ptr;
	while (*ptr)
	{
		if (is_delim(*ptr, delims) == 0)
		{
			*ptr++ = '\0';
			move_ptr(&ptr, delims);
			break ;
		}
		ptr++;
	}
	move_ptr(&ptr, delims);
	if (*ptr == '\0')
		ptr = NULL;
	return (token);
}
