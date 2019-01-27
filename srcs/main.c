/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:09:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/27 21:52:59 by rkulahin         ###   ########.fr       */
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
	t_list *list;

	j = 0;
	list = all->rooms;
	if (i <= 0 )
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

int		find_name(t_lem *all, char *str)
{
	int i;

	i = -1;
	while (++i < all->n_room)
		if (!ft_strcmp(str, all->name[i]))
			return(i);
	return(-1);
}

int		**malloc_connects(int i)
{
	int		**arr;
	int		j;
	int		k;

	j = -1;
	arr = (int **)malloc(sizeof(int *) * i);
	while (++j < i && (k = -1) == -1)
	{
		arr[j] = (int *)malloc(sizeof(int) * i);
		while (++k < i)
			arr[j][k] = 0;
	}	
	return(arr);
}

void	read_connects(t_lem *all, char *str)
{
	int		i;
	int		j;
	char	*first_name;
	char	*sec_name;

	all->connects = malloc_connects(all->n_room);
	i = 0;
	while (i >= 0)
	{
		if (str[0] == '#')
			continue ;
		else if (!ft_strchr(str, '-') || (str[0] == '#' && str[1] == '#'))
			exit(1);
		else
		{
			i = ft_strchr(str, '-') - str;
			first_name = malloc(sizeof(char) * i + 1);
			ft_strncpy(first_name, str, i);
			first_name[i] = '\0';
			sec_name = ft_strdup(ft_strchr(str, '-') + 1);
			i = find_name(all, first_name);
			j = find_name(all, sec_name);
			if (i == -1 || j == -1)
				exit(1);
			all->connects[i][j] = 1;
			all->connects[j][i] = 1;
			free(first_name);
			free(sec_name);
		}
		free(str);
		if (!get_next_line(g_fd, &str))
			return ;
	}
}

int		main()
{
	t_lem	*all;
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
	return(0);
}