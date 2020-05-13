/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_del_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:34:39 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 21:35:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		se_del_memory(void *content, size_t content_size)
{
	t_args	*tmp;

	tmp = (t_args *)content;
	ft_strdel(&tmp->name);
	ft_memdel((void **)&tmp);
	content_size = 0;
}
