/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:33:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/15 13:29:37 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../../includes/libft.h"

# define CBLACK "\x1B[30m"
# define CBLACKB "\x1B[1;30m"
# define CBBLACK "\x1B[90m"
# define CBBLACKB "\x1B[1;90m"

# define CRED "\x1B[31m"
# define CREDB "\x1B[1;31m"
# define CBRED "\x1B[91m"
# define CBREDB "\x1B[1;91m"

# define CGREEN "\x1B[32m"
# define CGREENB "\x1B[1;32m"
# define CBGREEN "\x1B[92m"
# define CBGREENB "\x1B[1;92m"

# define CYELLOW "\x1B[33m"
# define CYELLOWB "\x1B[1;33m"
# define CBYELLOW "\x1B[93m"
# define CBYELLOWB "\x1B[1;93m"

# define CBLUE "\x1B[34m"
# define CBLUEB "\x1B[1;34m"
# define CBBLUE "\x1B[94m"
# define CBBLUEB "\x1B[1;94m"

# define CMAGENTA "\x1B[35m"
# define CMAGENTAB "\x1B[1;35m"
# define CBMAGENTA "\x1B[95m"
# define CBMAGENTAB "\x1B[1;95m"

# define CCYAN "\x1B[36m"
# define CCYANB "\x1B[1;36m"
# define CBCYAN "\x1B[96m"
# define CBCYANB "\x1B[1;96m"

# define CWHITE "\x1B[37m"
# define CWHITEB "\x1B[1;37m"

# define CRESET "\x1B[0m"
# define CREVERSEVIDEO "\x1B[7m"
# define CUNDERLINED "\x1B[4m"
# define CULINEDREVV "\x1B[4;7m"

typedef struct	s_format
{
	char		*s_str;
	int			format;
	int			len;
	int			prec;
	int			width;
	int			hash;
	int			space;
	int			zero;
	int			minus;
	int			plus;
	int			sign;
	int			dot;
	char		*nbr;
	int			null;
	char		*star;
	int			fd;
}				t_format;

/*
********************************************************************************
**                                                                            **
**                         FORMAT FUNCTIONS                                   **
**                                                                            **
********************************************************************************
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				diouxf(t_format *f, va_list ap, int fd);
int				ft_parse_csp_percent(t_format *f, va_list ap);
int				ft_parse_f(t_format *f, va_list ap);
int				check_bef_format(t_format *f, long long print);
int				check_bef_format_u(t_format *f, unsigned long long print);
void			hh_h_ll_l(t_format *f, long long print, int base, int upper);
void			hh_h_ll_l_u(t_format *f, unsigned long long p, int b, int up);
void			ft_parse_precision(t_format *f);
void			ft_parse_flags(t_format *f);
void			ft_parse_width(t_format *f);

/*
********************************************************************************
**                                                                            **
**                         HELPER FUNCTIONS                                   **
**                                                                            **
********************************************************************************
*/

int				ft_check_if_width(t_format *f);
int				iszero(t_format *f);
int				ft_if_precision_diouxs(t_format *f);
void			swap_chars(t_format *f);
void			swap_0x(t_format *f);
int				which_len(t_format *f);
void			ft_put_zero(t_format *f);
void			ft_str_free(t_format *f, char *tmp, int i, int j);
void			ft_struct_del(t_format *f);
void			ft_set_struct_null(t_format **f);
int				ft_check_error(char *format);
char			ft_check_type(char c);
int				ft_len_format(char *f, unsigned int *i);
void			ft_form_struct(t_format *f, char *format,
				unsigned i, unsigned j);

/*
********************************************************************************
**                                                                            **
**                         BONUS FUNCTIONS                                    **
**                                                                            **
********************************************************************************
*/

int				printf_bonus(t_format *f, unsigned long long print);
void			define_asterisk(t_format *f, va_list ap);
int				print_array(t_format *f, char **array);

#endif
