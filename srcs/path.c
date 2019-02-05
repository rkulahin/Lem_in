/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:50:52 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/05 12:38:49 by rkulahin         ###   ########.fr       */
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
	return (tmp);
}

t_path	*add_room_to_path(t_path *path, t_room *room)
{
	t_link	*tmp;

	tmp = (t_link *)malloc(sizeof(t_link));
	tmp->room = room;
	tmp->next = path->path;
	path->path = tmp;
	return (path);
}

void	add_path(t_lem *all, t_path *new_path)
{
	
}

void	find_path(t_lem *all)
{
	t_room	*tmp;
	t_path	**new;
	int		k;

	while (find_end_zero(all->end->links))
	{
		tmp = all->end;
		k = 0;
		while (tmp->lvl != 0)
		{
			*new = add_room_to_path(*new,tmp);
			tmp = find_low_lvl(tmp->links);
			if (k = 0)
				(*new)->lengh = tmp->lvl + 1;
			if (tmp == NULL)
			{
				(*new)->lengh = -1;
				break ;
			}
			k = 1;
		}
		add_path(all, *new);
		new++;
	}
}
