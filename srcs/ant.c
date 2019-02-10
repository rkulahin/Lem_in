/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:02:23 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 12:26:43 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_ant_to_path(t_path *all, int ant)
{
	t_path	*tmp;
	t_path	*low;
	int		ants;

	ants = ant;
	while (ants && all)
	{
		tmp = all;
		low = tmp;
		while (tmp && tmp->next)
		{
			if (low->lengh + low->ants >= tmp->next->lengh + tmp->next->ants)
				low = tmp->next;
			tmp = tmp->next;
		}
		low->ants++;
		ants--;
	}
}

int		ant_on_path(t_link *path)
{
	t_link	*tmp;
	int		i;

	tmp = path;
	i = 0;
	while (tmp)
	{
		if (tmp->ant_busy)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	move_ant(t_link *path, int *ants, int *ants_on)
{
	t_link	*tmp;
	int		count_ant;

	count_ant = ant_on_path(path);
	while (count_ant)
	{
		tmp = path;
		while (tmp && !tmp->ant_busy)
			tmp = tmp->next;
		while (tmp && tmp->next && tmp->next->ant_busy)
			tmp = tmp->next;
		tmp->next->ant_busy = 1;
		tmp->next->n_ant = tmp->n_ant;
		tmp->n_ant = 0;
		tmp->ant_busy = 0;
		ft_printf("L%i-%s ", tmp->next->n_ant, tmp->next->room->name);
		if (!tmp->next->next)
		{
			tmp->next->ant_busy = 0;
			*ants -= 1;
			ants_on--;
			tmp->n_ant = 0;
		}
		count_ant--;
	}
}

int		move_first(t_link *path, int k, int *t)
{
	if (!path->ant_busy)
	{
		path->n_ant = k;
		path->ant_busy = 1;
		k++;
		ft_printf("L%i-%s ", path->n_ant, path->room->name);
		if (!path->next)
		{
			while (*t != 1)
			{
				path->n_ant++;
				ft_printf("L%i-%s ", path->n_ant, path->room->name);
				path->ant_busy = 0;
				*t -= 1;
			}
			ft_printf("\n");
			exit(1);
		}
	}
	return (k);
}

void	put_ant(t_lem *all)
{
	t_path	*tmp;
	int		k;
	int		t;

	k = 1;
	t = all->ants;
	while (all->ants)
	{
		ft_printf("\n");
		tmp = all->paths;
		while (tmp)
		{
			move_ant(tmp->path, &all->ants, &tmp->ants);
			if (tmp->ants && k <= t)
				k = move_first(tmp->path, k, &all->ants);
			tmp = tmp->next;
		}
	}
	ft_printf("\n");
}
