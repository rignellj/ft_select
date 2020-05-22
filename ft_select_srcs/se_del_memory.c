/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_del_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:34:39 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 16:24:20 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		se_del_memory(void *content, size_t content_size)
{
	t_args	*current_content;

	current_content = (t_args *)content;
	ft_strdel(&current_content->name);
	ft_memdel((void **)&current_content);
	content_size = 0;
}
