/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:34:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/27 20:34:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "lem_in_vizualizer.h"

int 	set_ant_dest(char **moves, t_all *all, int *ant_to_move)
{
	int 	i;
	t_ant	*ant;

	i = -1;
	*ant_to_move = 0;
	while (moves[++i])
	{
		if (!(ant = find_ant(all, atoi(&moves[i][1]))))
			return (1);
		ant->dest = find_room(strchr(moves[i], '-') + 1, all->info);
		if (!ant->dest)
			return (2);
	}
	*ant_to_move = i;
	return (0);
}

static int	get_delta_px(intmax_t dest, intmax_t pos, int speed)
{
	intmax_t	delta;

	delta = dest - pos;
	if (ft_abs(delta) > speed)
	{
		if (delta > 0)
			return (speed);
		else
			return (-speed);
	}
	return (delta);
}

/*
** return values:
**  -1: error with reading file
**   0: no moves left
**   1: ants moved to next rooms
*/

int 	ant_move(t_all *all)
{
	char 	**all_moves;
	t_ant	*ant;
	int 	i;
	int 	ant_in_way;
	char	*line;
	void	*img;

	int h, w;

	if ((i = get_next_line(all->fd, &line) <= 0))
	{
		ft_strdel(&line);
		return (i);
	}
	all_moves = ft_strsplit(line, ' ');
	ft_strdel(&line);
	set_ant_dest(all_moves, all, &ant_in_way);
	img = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
		"visualize/img/xpm/ant_go_left100x100.xpm", &h, &w);
	if (!img)
		return (-1);
	while (1)
	{
		i = -1;
		ant_in_way = 0;
		mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
		lemin_draw_edges(all->info, all->mlx);
		lemin_draw_rooms(all->info, all->mlx);
		while (all_moves[++i])
		{
			ant = find_ant(all, atoi(&all_moves[i][1]));
			if (ant->x != ant->dest->x && ant->y != ant->dest->y)
			{
				ant->x += get_delta_px(ant->dest->x, ant->x, all->speed);
				ant->y += get_delta_px(ant->dest->y, ant->y, all->speed);
				ant_in_way = 1;
			}
			mlx_put_image_to_window(all->mlx->mlx_ptr,
					all->mlx->win_ptr, img, ant->x, ant->y);
					printf("draw ant %jd, speed: %d at {%d:%d} dest {%d:%d}\n",
					ant->name, all->speed, ant->x, ant->y, ant->dest->x,
					 ant->dest->y);
		}
		usleep(1000 * 100);
		if (!ant_in_way)
			break;
	}
	ft_free_2arr(all_moves);
	return (1);
}
