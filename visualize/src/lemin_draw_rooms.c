/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_draw_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:38:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/27 16:38:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

void	lemin_draw_rooms(t_info *info, t_mlx *mlx)
{
	t_room	*room;
	int h;
	int w;
	void	*image;
	int color;

	room = info->rooms;
	while (room)
	{
		image = mlx_xpm_file_to_image(mlx->mlx_ptr, room->src, &h, &w);
		if (image)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, image, room->x, room->y);

		color = (room == info->start || room == info->end) ? 0x187c1d : 0x9b2606;
		if (info->map.print_name)
			mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, room->x, room->y - 15, color, room->name);
		room = room->next;
	}
}
