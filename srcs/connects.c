/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:47:10 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/30 16:05:06 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_name(t_lem *all, char *str)
{
	int i;

	i = -1;
	while (++i < all->n_room)
		if (!ft_strcmp(str, all->name[i]))
			return (i);
	return (-1);
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
	return (arr);
}

void	free_arr(char **str)
{
	free(str[0]);
	free(str[1]);
	free(str);
}

void	read_connects(t_lem *all, char *str)
{
	int		i;
	int		j;
	char	**name;

	all->connects = malloc_connects(all->n_room);
	i = 0;
	while (i >= 0)
	{
		if (str[0] == '#')
			continue ;
		else if (!ft_strchr(str, '-') ||
				ft_strcmp(ft_strchr(str, '-'), ft_strrchr(str, '-')))
			exit(1);
		else
		{
			name = ft_strsplit(str, '-');
			i = find_name(all, name[0]);
			j = find_name(all, name[1]);
			if (i == -1 || j == -1)
				exit(1);
			all->connects[i][j] = 1;
			all->connects[j][i] = 1;
			free_arr(name);
		}
		free(str);
		if (!get_next_line(g_fd, &str))
			return ;
	}
}
