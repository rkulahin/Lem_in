/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:21:54 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/03 17:43:07 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_ant(t_lem *all)
{
	if (get_next_line(g_fd, &all->line) > 0)
	{
		if ((all->ants = ft_atoi(all->line)) > 0)
		{
			free(all->line);
			return ;
		}
	}
	error();
}

void	save_room(t_room **tmp, char **str, int index)
{
	(*tmp)->name = ft_strdup(str[0]);
	(*tmp)->x = ft_atoi(str[1]);
	(*tmp)->y = ft_atoi(str[2]);
	(*tmp)->index = index;
	(*tmp)->busy = 0;
	(*tmp)->lvl = 0;
	(*tmp)->links = NULL;
	(*tmp)->next = malloc(sizeof(t_room *));
}

void	read_rooms(t_lem *all, int index)
{
	char	**str;
	int		k;
	t_room	*tmp;

	tmp = all->rooms;
	while (get_next_line(g_fd, &all->line) > 0)
	{
		if (all->line[0] == '#')
		{
			if (!ft_strcmp(all->line, "##start") ||
				(!ft_strcmp(all->line, "##end")))
				k = (!ft_strcmp(all->line, "##start") ? 1 : 2);
		}
		else if (ft_cwords(all->line, ' ') != 3)
		{
			tmp = NULL;
			return ;
		}
		else
		{
			str = ft_strsplit(all->line, ' ');
			if (str[0][0] == 'L')
				error();
			save_room(&tmp, str, index);
			if (k == 1 || k == 2)
			{
				if (((all->start) && k == 1) || ((all->end) && k == 2))
					error();
				if (k == 1)
					all->start = tmp;
				else
					all->end = tmp;
				k = 0;
			}
			tmp = tmp->next;
			index++;
		}
		free(all->line);
	}
}

void	save_link(t_room *f, t_room *s)
{
	t_room	*ft;
	t_room	*st;

	ft = f;
	st = s;
	while (f->links && f->links->name != NULL)
	{
			ft_printf("%s %s", f->links->name, s->name);

		if (!ft_strcmp(f->links->name, s->name))
			error();
		f->links = f->links->next;
	}
	f->links = s;
	f->links = ft->links;
	while (s->links && s->links->name != NULL)
	{
		if (!ft_strcmp(s->links->name, f->name))
			ft_printf("b");
			// error();
		s->links = s->links->next;
	}
	s->links = f;
	s->links = st->links;
}

void	read_links(t_lem *all)
{
	t_room	*tmp;
	char	**str;
	t_room	*f;
	t_room	*s;

	tmp = all->rooms;
	if (ft_cwords(all->line, '-') != 2)
		error();
	str = ft_strsplit(all->line, '-');
	while (tmp->name != NULL)
	{
		if (!ft_strcmp(tmp->name, str[0]))
			f = tmp;
		if (!ft_strcmp(tmp->name, str[1]))
			s = tmp;
		tmp = tmp->next;
	}
	if (!f || !s)
		error();
	free(all->line);
	save_link(f, s);
	while (get_next_line(g_fd, &all->line) > 0)
	{
		tmp = all->rooms;
		if (ft_cwords(all->line, '-') != 2)
			error();
		str = ft_strsplit(all->line, '-');
		while (tmp->name != NULL)
		{
			if (!ft_strcmp(tmp->name, str[0]))
				f = tmp;
			if (!ft_strcmp(tmp->name, str[1]))
				s = tmp;
			tmp = tmp->next;
		}
		if (!f || !s)
			error();
		save_link(f, s);
		free(all->line);
	}
}
