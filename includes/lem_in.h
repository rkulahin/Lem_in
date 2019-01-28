/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:10:04 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/28 14:25:52 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libftprintf/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

int				g_fd;

typedef	struct	s_lem
{
	int			ants;
	int			start;
	int			end;
	int			n_room;
	t_list		*rooms;
	int			**connects;
	char		**name;
	int			**way;
}				t_lem;

void			test(t_lem *all);

char			*read_rooms(t_lem *all);
t_list			*add_to_list(t_list *list, char *line);
void			read_name(t_lem *all, int i);

int				**malloc_connects(int i);
void			read_connects(t_lem *all, char *str);
int				find_name(t_lem *all, char *str);
void			free_arr(char **str);

#endif
