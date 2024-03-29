/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 12:53:43 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 12:54:35 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		change_lvl(t_room *room, int index)
{
	t_link	*links;
	int		k;

	k = 0;
	links = room->links;
	while (links)
	{
		k = 1;
		if (links->room->busy)
		{
			links->room->lvl = index + 1;
			links->room->busy = 0;
		}
		links = links->next;
	}
	return (k);
}

void	set_lvl(t_lem *all, int k, int index)
{
	t_room	*tmp;

	while (k != 0)
	{
		k = 0;
		tmp = all->rooms;
		while (tmp)
		{
			if (tmp->lvl == index)
				k = change_lvl(tmp, index);
			tmp = tmp->next;
		}
		index++;
	}
	all->mlvl = all->end->lvl - 1;
}

int		find_end_zero(t_link *link)
{
	t_link	*tmp;

	tmp = link;
	if (!tmp)
		error();
	while (tmp)
	{
		if (!tmp->room->busy)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_room	*find_low_lvl(t_link *find)
{
	t_room	*tmp;
	t_link	*tmp_link;

	tmp_link = find;
	tmp = tmp_link->room;
	while (tmp_link)
	{
		if (tmp->busy == 1)
			tmp = tmp_link->room;
		if (tmp->lvl > tmp_link->room->lvl && tmp_link->room->busy != 1)
			tmp = tmp_link->room;
		tmp_link = tmp_link->next;
	}
	if (tmp->busy == 1)
		return (NULL);
	if (tmp->lvl != 0)
		tmp->busy = 1;
	return (tmp);
}
