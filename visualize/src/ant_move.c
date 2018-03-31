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

#include "ft_mlx_image.h"
#include "lem_in_vizualizer.h"
#include <fcntl.h>
#include <unistd.h>
/*
int 	ant_move(t_all *all)
{
	int 	fd;
	int 	i;
	void	*image;
	char 	*img_name;
	t_room	*room1;
	int 	h, w;
	char 	*line;
	char 	**all_moves;
	char 	**move_arr;

	fd = open("ant_moves.txt", O_RDONLY);
	if (fd < 0)
		print_error("can't open file with ant moves\n");
	lemin_draw_edges(all->info, all->mlx);
	lemin_draw_rooms(all->info, all->mlx);
	i = -1;
	while (++i <= all->ant_step)
	{
		if (get_next_line(fd, &line) <= 0)
		{
			ft_strdel(&line);
			return (0);
		}
		if (i < all->ant_step)
			ft_strdel(&line);
	}
	all_moves = ft_strsplit(line, ' ');
	ft_strdel(&line);
	i = -1;
	while (all_moves[++i])
	{
		move_arr = ft_strsplit(all_moves[i], '-');
		room1 = find_room(move_arr[1], all->info);
		//printf("ant to room: %s\n", room1->name);
		image = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
					"visualize/img/xpm/ant_go_left100x100.xpm", &h, &w);
		//printf("get img\n");
		if (image)
			mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr,
								image, room1->x, room1->y);
	}
	all->ant_step++;
	close(fd);
	return (1);
}*/

int 	set_ant_dest(char **moves, t_all *all, int *ant_to_move)
{
	int 	i;
	t_ant	*ant;

	i = -1;
	*ant_to_move = 0;
	while (all_moves[++i])
	{
		if (!(ant = find_ant(all, atoi(&all_moves[i][1]))))
			return (1);
		ant->dest = find_room(strchr(all_moves[i], '-') + 1, all->info);
		if (!ant->dest)
			return (2);
	}
	*ant_to_move = i;
	return (0);
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

	if ((i = get_next_line(fd, &line) <= 0))
	{
		ft_strdel(&line);
		return (i);
	}
	all_moves = ft_strsplit(line, ' ');
	ft_strdel(&line);
	set_ant_dest(all_moves, all, &ant_in_way);
	while (1)
	{
		i = -1;
		while (all_moves[++i])
		{
			ant = find_ant(all, atoi(&all_moves[i][1]));
			ant->x += (ant->dest->x - ant->x) % speed;
			ant->y += (ant->dest->y - ant->y) % speed;
			if (ant->x == ant->dest->x && ant->y == ant->dest->y)
				ant_in_way--;
		}
		lemin_draw_edges(all->info, all->mlx);
		lemin_draw_rooms(all->info, all->mlx);
		if (!ant_in_way)
			break;
	}
	ft_free_2arr(all_moves);
	return (1);
}