/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:10:04 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/10 12:56:10 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libftprintf/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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
	char		*print;
	t_room		*rooms;
	t_room		*start;
	t_room		*end;
	t_path		*paths;
};

void			error(void);
t_lem			*init(void);
t_path			*init_path(void);

void			add_ant_to_path(t_path *all, int ant);
int				ant_on_path(t_link *path);
void			move_ant(t_link *path, int *ants, int *ants_on);
int				move_first(t_link *path, int k, int *t);
void			put_ant(t_lem *all);

int				read_links(t_lem *all);
void			add_links(t_link **m, t_room *add);

void			find_path(t_lem *all, int k);
int				valid_path(t_lem *all, t_path *new);
void			add_path(t_lem *all, t_path **new);
int				add_room_to_path(t_path *paths, t_room *room, int k);

t_room			*find_low_lvl(t_link *find);
int				find_end_zero(t_link *link);
void			set_lvl(t_lem *all, int k, int index);
int				change_lvl(t_room *room, int index);

void			read_rooms_links(t_lem *all, int index);
void			save_line(t_lem *all);
void			read_ant(t_lem *all);

void			add_room(t_room **rooms, t_room *new);
void			free_arr(char **str);
t_room			*new_room(char **str);
int				read_rooms(t_lem *all, int *index, int *k);

#endif
