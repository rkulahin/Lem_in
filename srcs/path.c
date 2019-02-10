/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:50:52 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 18:34:49 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_room_to_path(t_path *paths, t_room *room, int k)
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
			if (t == NULL)
				break ;
			t = new->path->next;
			free(new->path);
			new->path = t;
		}
		new->lengh = 0;
		free(new->path);
		new->path = NULL;
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
