/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 17:05:25 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/12 14:21:59 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_new_lines(int *len, char **array, t_format *f)
{
	int		i;

	i = 0;
	while (array[i])
	{
		*len += ft_strlen(array[i]) + 1;
		ft_putendl_fd(array[i++], f->fd);
	}
}

static void	print_spaces(int *len, char **array, t_format *f)
{
	int		spaces;
	int		i;

	i = 0;
	while (array[i])
	{
		spaces = f->width;
		*len += ft_strlen(array[i]) + spaces;
		ft_putstr_fd(array[i], f->fd);
		while (spaces--)
			write(f->fd, " ", 1);
		i++;
	}
}

int			print_array(t_format *f, char **array)
{
	int		len;

	f->null = array == 0 ? 1 : 0;
	len = 0;
	if (!f->null)
	{
		f->width ? print_spaces(&len, array, f) :
		print_new_lines(&len, array, f);
	}
	else
	{
		len = 6;
		ft_putstr_fd("(null)", f->fd);
	}
	ft_struct_del(f);
	return (len);
}
