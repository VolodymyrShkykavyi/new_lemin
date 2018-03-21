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

typedef struct		s_info
{
	uintmax_t		ants;
	uintmax_t		num_rooms;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
}					t_info;

void		run_hooks(t_mlx *mlx_info);
void   read_data(t_info *info);
int			parse_room(char *line, t_info *info);
int		is_comment(char *str);
int		is_edge(char *str);
int		is_room(char *str);
int		is_command(char *str);
void	print_error(char *str);
void 	print_rooms(t_info *info);

#endif
