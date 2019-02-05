/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/05 10:24:16 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test(t_lem *all)
{
	ft_printf("%i\n", all->mlvl);
	ft_printf("%i\n", all->ants);
	ft_printf("start: %s\n", all->start->name);
	ft_printf("end: %s\n", all->end->name);
	while (all->rooms)
	{
		ft_printf("room: %s x:%i y:%i lvl:%i\n", all->rooms->name, all->rooms->x, all->rooms->y, all->rooms->lvl);
		while (all->rooms->links)
		{
			ft_printf("[%s]", all->rooms->links->room->name);
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
	all->rooms = NULL;
	all->paths = NULL;
	all->start = NULL;
	all->end = NULL;
	return (all);
}

void	init_path(t_lem *all)
{
	t_link	*links;
	int		i;

	i = 0;
	links = all->end->links;
	while (links)
	{
		i++;
		links = links->next;
	}
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
	read_rooms_links(all, 0);
	init_path(all);
	set_lvl(all, 1, 0);
	test(all);
	return (0);
}
