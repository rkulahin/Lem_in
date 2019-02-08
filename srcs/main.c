/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/08 13:02:06 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test(t_lem *all)
{
	int i;

	i = 0;
	ft_printf("%i\n", all->mlvl);
	ft_printf("%i\n", all->ants);
	ft_printf("start: %s\n", all->start->name);
	ft_printf("end: %s\n", all->end->name);
	while (all->rooms && i < 716)
	{
		ft_printf("room: %s x:%i y:%i lvl:%i\n", all->rooms->name, all->rooms->x, all->rooms->y, all->rooms->lvl);
		while (all->rooms->links)
		{
			ft_printf("[%s]", all->rooms->links->room->name);
			all->rooms->links = all->rooms->links->next;
		}
		ft_printf("\n");
		all->rooms = all->rooms->next;
		i++;
	}
	i = 0;
	while (all->paths)
	{
		ft_printf("path %i path len:%i  ant:%i   : ", all->paths->index, all->paths->lengh, all->paths->ants);
		while (all->paths->path)
		{
			ft_printf("[%s] ", all->paths->path->room->name);
			all->paths->path = all->paths->path->next;
		}
		ft_printf("[antlen:%i]\n", all->paths->lengh + all->paths->ants);
		all->paths = all->paths->next;
		i++;
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
	all->line = NULL;
	return (all);
}

t_path	*init_path(void)
{
	t_path	*paths;

	paths = (t_path *)malloc(sizeof(t_path));
	paths->path = NULL;
	paths->next = NULL;
	paths->ants = 0;
	paths->index = 0;
	paths->lengh = 0;
	return (paths);
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
	if (!all->start || !all->end)
		error();
	all->start->lvl = 0;
	all->start->busy = 0;
	all->end->busy = 1;
	set_lvl(all, 1, 0);
	find_path(all, 0);
	add_ant_to_path(all->paths, all->ants);
	put_info(all);
	put_ant(all);
	// test(all);
	// system("Leaks lem_in");
	return (0);
}
