/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/27 08:38:58 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
t_list	*add_to_list(t_list *list, char *line)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	list->content = ft_strdup(line);
	tmp->content_size = list->content_size + 1;
	list->next = tmp;
	return (tmp);
}

void	read_rooms(t_lem *all)
{
	char	*line;
	t_list	*list;
	int		i;

	while (get_next_line(g_fd, &line) > 0)
	{
		i = 0;
		if (line[0] == '#')
		{
			if (!ft_strcmp("##start", line))
				all->start = list->content_size;
			else if (!ft_strcmp("##end", line))
				all->end = list->content_size;
			i = 1;
		}
		else if (!ft_strchr(line, ' '))
			break ;
		if (i == 0)
			all->rooms = add_to_list(all->rooms, line);
		free(line);
	}
}

int	main()
{
	t_lem	*all;
	char		*line;

	all = (t_lem *)malloc(sizeof(t_lem));
	all->rooms = (t_list *)malloc(sizeof(t_list));
	all->rooms->content_size = 0;
	g_fd = open("test", O_RDWR);
	get_next_line(g_fd, &line);
	all->ants = ft_atoi(line);
	if (all->ants > 0)
	{
		read_rooms(all);
	}
	return(0);
}