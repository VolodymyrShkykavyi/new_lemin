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

int			set_ant_dest(char **moves, t_all *all)
{
	int		i;
	t_ant	*ant;

	i = -1;
	while (moves[++i])
	{
		if (!(ant = find_ant(all, atoi(&moves[i][1]))))
			return (1);
		ant->dest = find_room(strchr(moves[i], '-') + 1, all->info);
		if (!ant->dest)
			return (2);
	}
	return (0);
}

char		**get_new_moves(t_all *all)
{
	char	**all_moves;
	char	*line;
	int		ret;

	if ((ret = get_next_line(all->fd, &line) <= 0))
	{
		ft_strdel(&line);
		if (ret < 0)
			print_error("can't read file with moves\n");
		else
			return (NULL);
	}
	all_moves = ft_strsplit(line, ' ');
	ft_strdel(&line);
	set_ant_dest(all_moves, all);
	return (all_moves);
}

/*
** return values:
**  -1: error with reading file
**   0: no moves left
**   1: ants moved to next rooms
*/

int			ant_move(t_all *all)
{
	void	*img;
	int		h;
	int		w;

	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	lemin_draw_edges(all->info, all->mlx);
	lemin_draw_rooms(all->info, all->mlx);
	if (draw_ants(all, 1) == 0)
	{
		img = mlx_xpm_file_to_image(all->mlx->mlx_ptr,
					"visualize/img/xpm/ant_wait100x100.xpm", &h, &w);
		if (img)
			mlx_put_image_to_window(all->mlx->mlx_ptr,
					all->mlx->win_ptr, img, all->info->end->x,
					all->info->end->y);
	}
	return (1);
}
