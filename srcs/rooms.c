/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:45:39 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/28 14:25:26 by rkulahin         ###   ########.fr       */
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
	int		j;
	int		len;
	t_list	*list;

	j = 0;
	list = all->rooms;
	if (i <= 0)
		exit(1);
	all->name = (char **)malloc(sizeof(char *) * i);
	while (j < i)
	{
		len = ft_strchr(list->content, ' ') - (char *)list->content;
		all->name[j] = malloc(sizeof(char) * len + 1);
		ft_strncpy(all->name[j], list->content, len);
		all->name[j][len] = '\0';
		list = list->next;
		j++;
	}
	all->n_room = i;
}

char	*read_rooms(t_lem *all)
{
	char	*line;
	t_list	*list;
	int		k;

	list = all->rooms;
	while (get_next_line(g_fd, &line) > 0)
	{
		k = 0;
		if (line[0] == '\0')
			exit(1);
		else if (line[0] == '#')
		{
			if (!ft_strcmp("##start", line))
				all->start = list->content_size;
			else if (!ft_strcmp("##end", line))
				all->end = list->content_size;
		}
		else if (!ft_strchr(line, ' '))
			break ;
		else
			list = add_to_list(list, line);
		free(line);
	}
	read_name(all, list->content_size);
	return (line);
}
