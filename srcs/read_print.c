/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:23:35 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 18:36:44 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	save_to_read(t_lem *all, t_read *new)
{
	if (!all->print)
	{
		all->print = new;
		all->print->last = new;
		return ;
	}
	all->print->last->next = new;
	all->print->last = new;
}

void	print_read(t_lem *all)
{
	t_read *t;

	t = all->print;
	while (t)
	{
		ft_printf("%s\n", t->str);
		t = t->next;
	}
}

t_read	*init_read(t_lem *all)
{
	t_read	*new;

	new = (t_read *)malloc(sizeof(t_read));
	new->next = NULL;
	new->last = NULL;
	new->str = ft_strdup(all->line);
	return (new);
}
