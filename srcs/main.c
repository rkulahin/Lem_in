/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/03 17:09:54 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test(t_lem *all)
{
	ft_printf("%i\n", all->ants);
	ft_printf("start: %s\n", all->start->name);
	ft_printf("end: %s\n", all->end->name);
	while (all->rooms->name != NULL)
	{
		ft_printf("room: %s x:%i y:%i index:%i\n", all->rooms->name, all->rooms->x, all->rooms->y, all->rooms->index);
		while (all->rooms->links)
		{
			ft_printf("[%s]", all->rooms->links->name);
			all->rooms->links = all->rooms->links->next;
		}
		ft_printf("\n");
		all->rooms = all->rooms->next;
	}
}

void	error(void)
{
	ft_printf("ERROR");
	exit(1);
}

t_lem	*init(void)
{
	t_lem *all;

	all = (t_lem *)malloc(sizeof(t_lem));
	all->rooms = (t_room *)malloc(sizeof(t_room));
	all->rooms->name = NULL;
	all->rooms->next = NULL;
	all->paths = (t_path **)malloc(sizeof(t_path *));
	all->start = NULL;
	all->end = NULL;
	return (all);
}

int		main(int ac, char **av)
{
	t_lem		*all;

	if (ac != 2)
		error();
	g_fd = open(av[1], O_RDWR);
	if (g_fd <= 0)
		error();
	all = init();
	read_ant(all);
	read_rooms(all, 0);
	read_links(all);
	test(all);
	return (0);
}
