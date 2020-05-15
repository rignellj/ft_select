/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_clear_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:01:14 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/15 13:27:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
// #include <term.h>

void	se_clear_screen(void)
{
	ft_dprintf(STDERR_FILENO, "%s", "\x1B[2J\x1B[H");
}
