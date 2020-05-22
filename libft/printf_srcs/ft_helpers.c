/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:20:05 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 17:22:21 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_str_free(t_format *f, char *tmp, int i, int j)
{
	char	*new_nbr;

	new_nbr = NULL;
	if (j && !tmp)
		exit(2);
	if (!i)
	{
		if (!(new_nbr = *f->nbr == '\0' ? ft_strdup("\0") : ft_strdup(f->nbr)))
			exit(2);
		ft_strdel(&f->nbr);
		if ((f->width || f->format == 's' || f->format == 'f'))
			if (!(f->nbr = ft_strjoin(new_nbr, tmp)))
				exit(2);
	}
	else
	{
		if (!(new_nbr = ft_strdup(f->nbr)))
			exit(2);
		ft_strdel(&f->nbr);
		f->nbr = ft_strjoin(tmp, new_nbr);
	}
	ft_strdel(&tmp);
	ft_strdel(&new_nbr);
}

void	ft_put_zero(t_format *f)
{
	ft_bzero(f, sizeof(t_format));
}

void	swap_chars(t_format *f)
{
	int		i;

	i = 0;
	while (f->nbr[i] && f->nbr[0] == '0')
	{
		if (f->nbr[i] == '+')
		{
			f->nbr[i] = '0';
			*f->nbr = '+';
			return ;
		}
		else if (f->nbr[i] == '-')
		{
			f->nbr[i] = '0';
			*f->nbr = '-';
			return ;
		}
		else if (f->nbr[i] == ' ' && ft_isdigit(f->nbr[i + 1]))
		{
			f->nbr[i] = '0';
			*f->nbr = ' ';
			return ;
		}
		i++;
	}
}

void	swap_0x(t_format *f)
{
	char	*c;
	char	*b;

	c = NULL;
	b = NULL;
	if (!(c = ft_strchr(f->s_str, 'X')))
		if (!(c = ft_strchr(f->s_str, 'x')))
			return ;
	if (!(b = ft_strchr(f->nbr, *c)))
	{
		c = NULL;
		return ;
	}
	if (f->nbr[0] == '0' && f->nbr[1] != *c && b)
	{
		f->nbr[1] = *c;
		*b = '0';
	}
	c = NULL;
	b = NULL;
}

void	ft_struct_del(t_format *f)
{
	if (f->s_str)
		ft_strdel(&f->s_str);
	if (f->nbr)
	{
		free(f->nbr);
		f->nbr = NULL;
	}
	f = NULL;
}
