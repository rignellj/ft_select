/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_clear_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:01:14 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 16:06:36 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

void	se_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putint_fd);
}
