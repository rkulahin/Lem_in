/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:02:36 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/30 16:31:20 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	if_last_room(t_lem *all, int i)
{
	if (all->connects[i][all->end])
	{
		all->path[++(all->p_index)] = i;
		all->path[++(all->p_index)] = all->end;
		return (1);
	}
	return (0);
}

void	del_elem(t_lem *all, int i, int path)
{
	all->connects[all->curr_room][i] = 0;
	all->connects[i][all->curr_room] = 0;
	if (path)
	{
		all->path[all->p_index] = -1;
		all->p_index--;
	}
}

int	find_room(t_lem *all, int r, int d)
{
	while (d < all->n_room)
	{
		if (all->connects[r][++d] == 1)
			return (d);
	}
	return (0);
}

int	is_in_path(t_lem *all, int r)
{
	int i;

	i = -1;
	while (all->path[++i] != -1)
	{
		if (all->path[i] == r)
			return (1);
	}
	return (0);
}

int			algo_lem(t_lem *all, int i)
{
	if (all->connects[0][all->n_room - 1])
	{
		all->path[++(all->p_index)] = all->n_room - 1;
		return (1);
	}
	while ((i = find_room(all, all->curr_room, i)))
	{
		if (if_last_room(all, i))
			return (1);
		else if (is_in_path(all, i))
			del_elem(all, i, 0);
	}
	if ((all->curr_room = find_room(all, all->curr_room, 0)) == 0)
	{
		if (all->p_index == 0 || all->curr_room == 0)
			return (0);
		all->curr_room = all->path[all->p_index - 1];
		del_elem(all, all->path[all->p_index], 1);
		if (algo_lem(all, 0))
			return (1);
	}
	all->path[++(all->p_index)] = all->curr_room;
	if (algo_lem(all, 0))
		return (1);
	return (0);
}
