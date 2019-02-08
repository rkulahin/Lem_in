/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:02:35 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/08 13:11:39 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_room(t_room *rooms, t_room *start, t_room *end)
{
	while (rooms)
	{
		if (start->index == rooms->index)
			ft_printf("##start\n");
		if (end->index == rooms->index)
			ft_printf("##end\n");
		ft_printf("%s %i %i\n", rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}
}

void	put_info(t_lem *all)
{
	ft_printf("%i\n", all->ants);
	print_room(all->rooms, all->start, all->end);
}
