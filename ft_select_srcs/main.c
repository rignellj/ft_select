/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/22 16:40:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putint_fd(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

int		main(int ac, char *av[])
{
	t_sh		t;

	se_init(&t, ac, av);
	se_enable_rawmode(&t);
	se_init_signal_handlers();
	se_put_args_linkedlist(&t);
	se_process_input(&t);
	se_disable_rawmode(&t);
	se_print_options_stdout(&t);
	se_close(&t);
	return (0);
}
