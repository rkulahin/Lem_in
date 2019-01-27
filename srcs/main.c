/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/27 09:50:57 by rkulahin         ###   ########.fr       */
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

void	read_name(t_lem *all, int i)
{
	int	j;
	int	len;

	j = 0;
	if (i <= 0 )
		exit(1);
	all->name = (char **)malloc(sizeof(char *) * i);
	while(j < i)
	{
		len = ft_strchr(all->rooms->content, ' ') - &all->rooms->content;
		all->name[j] = malloc(sizeof(char) * len + 1);
		ft_strncpy(all->name[j], all->rooms->content, len);
		all->name[j][len + 1] = '\0';
		j++;
	}
	all->n_room = i;
}

void	read_rooms(t_lem *all)
{
	char	*line;
	t_list	*list;
	int		k;

	while (get_next_line(g_fd, &line) > 0)
	{
		k = 0;
		if (line[0] == '#')
		{
			if (!ft_strcmp("##start", line))
				all->start = list->content_size;
			else if (!ft_strcmp("##end", line))
				all->end = list->content_size;
		}
		else if (!ft_strchr(line, ' '))
			break ;
		else
			list = add_to_list(all->rooms, line);
		free(line);
	}
	read_name(all, all->rooms->content_size - 1);
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