/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:06:11 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/12 14:29:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list			ap;
	unsigned int	i;
	unsigned int	j;
	t_format		f;
	int				ret;

	va_start(ap, format);
	i = 0;
	ret = 0;
	while (format[i] && ft_check_error((char*)format))
	{
		j = 1;
		if (format[i] == '%')
		{
			j = ft_len_format((char*)format, &i);
			ft_form_struct(&f, (char*)format, i + 1, j);
			ret += diouxf(&f, ap, fd) - 1;
			i += j + 1;
		}
		else
			write(1, &format[i++], 1);
		ret++;
	}
	va_end(ap);
	return (ret);
}
