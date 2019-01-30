/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:10:04 by rkulahin          #+#    #+#             */
/*   Updated: 2019/01/30 16:32:48 by rkulahin         ###   ########.fr       */
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
	int			p_index;
	t_list		*rooms;
	int			**connects;
	char		**name;
	int			*path;
	int			curr_room;

}				t_lem;

void			test(t_lem *all);

char			*read_rooms(t_lem *all);
t_list			*add_to_list(t_list *list, char *line);
void			read_name(t_lem *all, int i);

int				**malloc_connects(int i);
void			read_connects(t_lem *all, char *str);
int				find_name(t_lem *all, char *str);
void			free_arr(char **str);

int				algo_lem(t_lem *all, int i);
int				if_last_room(t_lem *all, int i);
void			del_elem(t_lem *all, int i, int path);
int				find_room(t_lem *all, int r, int d);
int				is_in_path(t_lem *all, int r);

void			print_all(t_lem *all);
void			print_ant(t_lem *all, int n);

#endif
