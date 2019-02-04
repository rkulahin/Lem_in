/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:21:54 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/04 14:22:46 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_ant(t_lem *all)
{
	if (get_next_line(g_fd, &all->line) > 0)
	{
		if ((all->ants = ft_atoi(all->line)) > 0)
		{
			free(all->line);
			return ;
		}
	}
	error();
}

void	read_rooms_links(t_lem *all, int index)
{
	t_room	*tmp;
	int		k;

	tmp = all->rooms;
	k = 0;
	while (get_next_line(g_fd, &all->line) > 0)
	{
		if (read_rooms(all, &index, &k))
			;
		else if (ft_strequ(all->line, "##start") ||
					ft_strequ(all->line, "##end"))
			k = (all->line[2] == 's' ? 1 : 2);
		else if (all->line[0] == '#')
			;
		else if (ft_cwords(all->line, '-') == 2)
		{
			index = 1;
			if (!read_links(all))
				error();
		}
		else
			error();
		free(all->line);
	}
}
