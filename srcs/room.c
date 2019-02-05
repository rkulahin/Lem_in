/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:23:18 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/05 17:39:32 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room(t_room **rooms, t_room *new)
{
	t_room *tmp;

	tmp = *rooms;
	if (*rooms == NULL)
	{
		new->index = 0;
		*rooms = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	new->index = tmp->index + 1;
	tmp->next = new;
}

void	free_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
}

t_room	*new_room(char **str)
{
	t_room *new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(str[0]);
	new->x = ft_atoi(str[1]);
	new->y = ft_atoi(str[2]);
	new->lvl = -1;
	new->busy = 1;
	new->next = NULL;
	free_arr(str);
	return (new);
}

int		read_rooms(t_lem *all, int *index, int *k)
{
	t_room	*new;
	char	**str;

	if (ft_cwords(all->line, ' ') == 3 && all->line[0] != '#' &&
		all->line[0] != 'L')
	{
		if (*index == 1)
			error();
		str = ft_strsplit(all->line, ' ');
		new = new_room(str);
		add_room(&all->rooms, new);
		if (*k == 1)
			all->start = new;
		else if (*k == 2)
			all->end = new;
		*k = 0;
		return (1);
	}
	return (0);
}
