/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:10:04 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/08 13:11:21 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libftprintf/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int				g_fd;

typedef	struct s_lem	t_lem;
typedef	struct s_room	t_room;
typedef	struct s_path	t_path;
typedef struct s_link	t_link;

struct			s_link
{
	t_room		*room;
	int			n_ant;
	int			ant_busy;
	t_link		*next;
};

struct			s_room
{
	char		*name;
	int			x;
	int			y;
	int			lvl;
	int			index;
	int			busy;
	t_link		*links;
	t_room		*next;
};

struct			s_path
{
	t_link		*path;
	int			index;
	int			lengh;
	int			ants;
	t_path		*next;
};

struct			s_lem
{
	int			ants;
	int			mlvl;
	char		*line;
	t_room		*rooms;
	t_room		*start;
	t_room		*end;
	t_path		*paths;
};

void			read_ant(t_lem *all);
void			read_rooms_links(t_lem *all, int index);
void			error();
void			free_arr(char **str);
void			test(t_lem *all);

void			add_room(t_room **rooms, t_room *new);
t_room			*new_room(char **str);
int				read_rooms(t_lem *all, int *index, int *k);

void			add_links(t_link **m, t_room *add);
int				read_links(t_lem *all);

void			set_lvl(t_lem *all, int k, int index);
t_path			*init_path(void);
void			find_path(t_lem *all, int k);
int				add_room_to_path(t_path *paths, t_room *room, int k);
t_room			*find_low_lvl(t_link *find);
int				find_end_zero(t_link *link);

void			add_ant_to_path(t_path *all, int ants);
void			put_ant(t_lem *all);
int				move_first(t_link *path, int k);
void			move_ant(t_link *path, int *ants, int *ants_on);

void			put_info(t_lem *all);
void			print_room(t_room *rooms, t_room *start, t_room *end);

#endif
