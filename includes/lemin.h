/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:27:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/15 20:27:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define MALL_CHECK(x) if (!(x)) exit (1)
# define DEBUG 1

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_room
{
	int				x;
	int				y;
	int				weight;
	int				visited;
	uintmax_t		ant;
	unsigned int	num_edges;
	char			*name;
	struct s_edge	*edges;
	struct s_room	*next;
}					t_room;

typedef struct		s_edge
{
	t_room			*room;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_way
{
	t_edge			*edges;
	uintmax_t		len;
	struct s_way	*next;
}					t_way;

typedef struct		s_info
{
	int				fd;
	uintmax_t		ant_num;
	uintmax_t		num_rooms;
	t_room			*rooms;
	t_way			*ways;
	t_room			*start;
	t_room			*end;
}					t_info;


/*
** debug
*/

void				print_rooms(t_info *info);
void				print_ways(t_way *ways);

void				read_file(t_info *info);
int					parse_room(char *line, t_info *info);
t_room				*find_room(char *name, t_info *info);
void				valid_and_set_weight(t_info *info);
int					parse_edge(char *line, t_info *info);
void				find_ways(t_info *info);
void 				save_ways(t_way *arr, t_info *info);
void				print_result(t_info *info);
void				print_error(char *text);

t_edge				*get_last_edge(t_edge *edges);
int					is_command(char *str);
//int					is_command_support(char *str);
int					is_room(char *str);
int					is_edge(char *str);
int					is_comment(char *str);
#endif
