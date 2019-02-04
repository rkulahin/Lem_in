/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:50:52 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/04 18:19:41 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_lvl(t_lem *all, int k, int index)
{
	t_room	*tmp;

	all->start->lvl = 0;
	all->start->busy = 0;
	while (k != 0)
	{
		k = 0;
		tmp = all->rooms;
		while (tmp)
		{
			if (tmp->lvl == index)
				while (tmp->links)
				{
					k = 1;
					if (tmp->links->room->busy)
					{
						tmp->links->room->lvl = index + 1;
						tmp->links->room->busy = 0;
					}
					tmp->links = tmp->links->next;
				}
			tmp = tmp->next;
		}
		index++;
	}
	all->mlvl = all->end->lvl - 1;
}

void	find_path(t_lem *all)
{
	t_room	*tmp;
	t_path	*new;

	tmp = all->end;
	while ()
	while (all->mlvl != 0)
	{
		add_path(all,tmp);

	}
}
