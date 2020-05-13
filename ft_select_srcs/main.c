/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 18:29:22 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
// #include <term.h>
// #include <stdlib.h>

int		ft_putint_fd(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

int		main(int ac, char *av[], char *env[])
{
	t_sh		t;

	se_init(&t, ac, av, env);
	// se_clear_screen();
	se_enable_rawmode(&t);
	se_put_args_linkedlist(&t);
	se_process_input(&t);
	se_disable_rawmode(&t);
	se_print_options_stdout(&t);
	se_clear_screen();
	se_close(&t);
	return (0);
}

/*
	char		*rev;

	rev = CREVERSEVIDEO;
	ft_dprintf(1 ,"reverse video in bits: 	%b\nunderline in bits:	%b\nunderlinedrever in bits:%b\n", CREVERSEVIDEO, CUNDERLINE, CUNDERLINEDREVERSEVIDEO);
	ft_dprintf(1, "this is %sreversevideo%s\n\nthis is %sunderlined%s\n\nthis is %scombination%s\n", CREVERSEVIDEO, CRESET, CUNDERLINE, CRESET, CUNDERLINEDREVERSEVIDEO, CRESET);
	ft_dprintf(1, CUNDERLINEDREVERSEVIDEO"this is combination%s\n", CRESET);
	exit(1);

*/
