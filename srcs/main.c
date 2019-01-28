/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/28 14:58:17 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test(t_lem *all)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("number of ants: %i\n", all->ants);
	ft_printf("number of rooms: %i\n", all->n_room);
	ft_printf("start: %s\nend: %s\n", all->name[all->start], all->name[all->end]);
	while (i < all->n_room)
	{
		ft_printf("%s :%i:\n", all->name[i], i);
		i++;
	}
	i = -1;
	while (++i < all->n_room && (j = -1) == -1)
	{
		while (++j < all->n_room)
			ft_printf("%i", all->connects[i][j]);
		ft_printf("\n");
	}
}

int		main(void)
{
	t_lem		*all;
	char		*line;

	all = malloc(sizeof(t_lem));
	all->rooms = malloc(sizeof(t_list));
	all->rooms->content_size = 0;
	g_fd = open("test", O_RDWR);
	get_next_line(g_fd, &line);
	all->ants = ft_atoi(line);
	free(line);
	if (all->ants > 0)
	{
		line = read_rooms(all);
		read_connects(all, line);
		// algo_lem(all);
		test(all);
	}
	return (0);
}
