/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:21:54 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 12:48:50 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_ant(t_lem *all)
{
	if (get_next_line(0, &all->line) > 0)
	{
		if ((all->ants = ft_atoi(all->line)) > 0)
		{
			save_line(all);
			free(all->line);
			return ;
		}
	}
	error();
}

void	save_line(t_lem *all)
{
	char	*ptr;

	ptr = all->print;
	all->print = ft_strjoin(all->print, all->line);
	free(ptr);
	ptr = all->print;
	all->print = ft_strjoin(all->print, "\n");
	free(ptr);
}

void	read_rooms_links(t_lem *all, int index)
{
	t_room	*tmp;
	int		k;

	tmp = all->rooms;
	k = 0;
	while (get_next_line(0, &all->line) > 0)
	{
		save_line(all);
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
