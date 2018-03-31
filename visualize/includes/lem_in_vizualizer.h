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
# define IMG_W 110
# define IMG_H 110
# define OFFSET 30

# include "ft_mlx_image.h"
# include "../../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_room
{
	intmax_t		x;
	intmax_t		y;
	char			ant_in;
	char			src[50];
	char 			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_ant
{
	uintmax_t		name;
	intmax_t		x;
	intmax_t		y;
	t_room			*dest;
	struct s_ant	*next;
}					t_ant;

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
	int 					print_name;
	int 					map_drawed;
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

typedef struct		s_all
{
	int 			fd;
	unsigned int	speed;
	t_info			*info;
	t_mlx			*mlx;
	uintmax_t		ant_step;
	t_ant			*ants;
}					t_all;

void		run_hooks(t_mlx *mlx_info, t_info *info);
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
void	lemin_draw_edges(t_info *info, t_mlx *mlx);
void	lemin_draw_rooms(t_info *info, t_mlx *mlx);
void	scale_rooms_coord(t_info *info);
int 	ant_move(t_all *all);
t_ant	*find_ant(t_all *all, uintmax_t name);

#endif
