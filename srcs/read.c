/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:21:54 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/03 12:46:36 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_ant(t_lem *all)
{
	if (get_next_line(g_fd, &all->line) > 0)
	{
		if ((all->ants = ft_atoi(all->line)) > 0);
			return ;
	}
	error();
}

void	save_room(t_room **tmp, char **str, int index)
{
	(*tmp)->name = ft_strdup(str[0]);
	(*tmp)->x = ft_atoi(str[1]);
	(*tmp)->y = ft_atoi(str[2]);
	(*tmp)->index = index;
	(*tmp)->b = 0;
	(*tmp)->lvl = 0;
	(*tmp)->next = malloc(sizeof(t_room *));
}

void	read_rooms(t_lem *all)
{
	char	**str;
	int		index;
	int		k;
	t_room	*tmp;

	all->rooms = malloc(sizeof(t_room *));
	tmp = all->rooms;
	index = 0;
	while (get_next_line(g_fd, &all->line) > 0)
	{
		if (all->line[0] == '#')
		{
			if (!ft_strcmp(all->line, "##start") || (!ft_strcmp(all->line, "##end")))
				k = (!ft_strcmp(all->line, "##start") ? 1 : 2);
		}
		else if (ft_cwords(all->line, ' ') != 3)
			return ;
		else
		{
			str = ft_strsplit(all->line, ' ');
			if (str[0][0] == 'L')
				error();
			save_room(tmp, str, index);
			if (k == 1)
				all->start = tmp;
			else if (k == 2)
				all->end = tmp;
			tmp = tmp->next;
			index++;
		}
	}
}
