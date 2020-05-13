/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_put_args_linkedlist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:03:05 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/13 13:56:20 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void se_create_list(t_list **node, char *name)
{
	t_list	*new;
	t_args	content;

	content.is_picked = FALSE;
	content.cursor = FALSE;
	if (!(content.name = ft_strdup(name)))
		se_exit("Malloc *** error\n");
	new = ft_lstnew(&content, sizeof(t_args));
	ft_lstappend(node, new);
}

void	se_put_args_linkedlist(t_sh *t)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = NULL;
	while (t->av[i])
	{
		se_create_list(&node, t->av[i]);
		i++;
	}
	t->head = node;
	((t_args *)t->head->content)->cursor = TRUE;
}

/*
	void		ls_lstadd_linkedlist(t_list **node, t_ls *f, char *s, int i)
	{
		t_list		*new_node;
		t_file		content;
		struct stat	buf;

		if (lstat(s, &buf) == -1)
			ls_error(s);
		ft_bzero(&content, sizeof(t_file));
		f->num_of_nodes++;
		content.path = s;
		content.name = i ? s : ret_name(s);
		if (f->max_name_len < ((int)ft_strlen(i ? s : (ret_name(s)))))
			f->max_name_len = ft_strlen(i ? s : (ret_name(s)));
		ls_type_mode(&buf, &content);
		if (f->l)
			ls_get_data_l_flag(f, &content, &buf);
		if (f->t)
			content.epoc = buf.st_mtime;
		new_node = ft_lstnew(&content, sizeof(t_file));
		ft_lstadd(node, new_node);
	}

*/