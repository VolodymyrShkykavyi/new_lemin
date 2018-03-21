/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_vizualizer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:47:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/13 12:47:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_VIZUALIZER_H
# define LEM_IN_VIZUALIZER_H
# define MALL_CHECK(x) if (!(x)) exit (1)
# define IMG_W 50
# define IMG_H 50

# include "ft_mlx_image.h"
# include "../../libft/includes/libft.h"
# include <stdlib.h>

typedef struct		s_room
{
	intmax_t		x;
	intmax_t		y;
	char			ant_in;
	char			src[50];
	char 			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_edge
{
	t_room					*room1;
	t_room					*room2;
	struct s_edge		*next;
}									t_edge;

typedef struct		s_map
{
	intmax_t				min_x;
	intmax_t				min_y;
	intmax_t				max_x;
	intmax_t				max_y;
}									t_map;

typedef struct		s_info
{
	uintmax_t		ants;
	uintmax_t		num_rooms;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_edge			*edges;
	t_map				map;
}					t_info;

void		run_hooks(t_mlx *mlx_info);
void   read_data(t_info *info);
int			parse_room(char *line, t_info *info);
int			parse_edge(char *line, t_info *info);
int		is_comment(char *str);
int		is_edge(char *str);
int		is_room(char *str);
int		is_command(char *str);
t_room		*find_room(char *name, t_info *info);
void	print_error(char *str);
void 	print_rooms(t_info *info);
void print_edges(t_info *info);

#endif
