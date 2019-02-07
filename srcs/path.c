/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:50:52 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/07 18:06:40 by rkulahin         ###   ########.fr       */
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

int	add_room_to_path(t_path *paths, t_room *room, int k)
{
	t_link	*tmp;

	tmp = (t_link *)malloc(sizeof(t_link));
	tmp->room = room;
	tmp->n_ant = 0;
	tmp->ant_busy = 0;
	tmp->next = paths->path;
	paths->path = tmp;
	k++;
	return (k);
}

void	add_path(t_lem *all, t_path **new)
{
	t_path	*tmp;

	tmp = all->paths;
	if (all->paths == NULL)
	{
		all->paths = *new;
		all->paths->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	(*new)->index = tmp->index + 1;
	tmp->next = (*new);
}

int		valid_path(t_lem *all, t_path *new)
{
	t_path	*tmp;
	t_link	*t;

	tmp = all->paths;
	if (new->lengh == -1)
	{
		while (new->path)
		{
			t = new->path->next;
			if (t == NULL)
				break ;
			free(new->path);
			new->path = t;
		}
		new->lengh = 0;
		free(new->path);
		new->path = NULL;
		free(new);
		return (0);
	}
	add_path(all, &new);
	return (1);
}

void	find_path(t_lem *all, int k)
{
	t_room	*tmp;
	t_path	*new;

	new = init_path();
	while (find_end_zero(all->end->links))
	{
		tmp = all->end;
		k = 0;
		while (tmp != NULL && tmp->lvl != 0)
		{
			k = add_room_to_path(new, tmp, k);
			tmp = find_low_lvl(tmp->links);
		}
		if (tmp == NULL)
			new->lengh = -1;
		else
			new->lengh = k;
		if (valid_path(all, new))
		{
			if (new->lengh == 1)
				return ;
			new = init_path();
		}
	}
	free(new);
}
