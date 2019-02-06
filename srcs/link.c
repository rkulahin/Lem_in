/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:19:02 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/06 14:39:22 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_links(t_link **m, t_room *add)
{
	t_link *tmp;

	tmp = *m;
	if ((*m) == NULL)
	{
		(*m) = (t_link *)malloc(sizeof(t_link));
		(*m)->next = NULL;
		(*m)->room = add;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_link *)malloc(sizeof(t_link));
	tmp->next->room = add;
	tmp->next->next = NULL;
}

int		read_links(t_lem *all)
{
	char	**str;
	t_room	*first;
	t_room	*second;
	t_room	*rooms;

	rooms = all->rooms;
	str = ft_strsplit(all->line, '-');
	while (rooms)
	{
		if (ft_strequ(rooms->name, str[0]))
			first = rooms;
		if (ft_strequ(rooms->name, str[1]))
			second = rooms;
		rooms = rooms->next;
	}
	free_arr(str);
	if (first && second)
	{
		add_links(&first->links, second);
		add_links(&second->links, first);
		return (1);
	}
	return (0);
}
