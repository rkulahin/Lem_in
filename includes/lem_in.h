/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:10:04 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/03 17:17:25 by rkulahin         ###   ########.fr       */
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

struct			s_room
{
	char		*name;
	int			x;
	int			y;
	int			lvl;
	int			index;
	int			busy;
	t_room		*links;
	t_room		*next;
};

struct			s_path
{
	t_room		*room;
	t_path		*next;
};

struct			s_lem
{
	int			ants;
	char		*line;
	t_room		*rooms;
	t_room		*start;
	t_room		*end;
	t_path		**paths;
};

void			read_ant(t_lem *all);
void			save_room(t_room **tmp, char **str, int index);
void			read_rooms(t_lem *all, int index);
void			error();
void			read_links(t_lem *all);
void			save_link(t_room *f, t_room *s);


#endif
