/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 18:49:30 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	all->print = NULL;
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

int		main(void)
{
	t_lem		*all;

	g_fd = open("test.txt", O_RDWR);
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
	print_read(all);
	if (all->start->links)
		put_ant(all);
	return (0);
}
