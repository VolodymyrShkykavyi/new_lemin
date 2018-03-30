/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_draw_edges.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:58:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/27 15:58:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

static void	draw_fon(t_info *info, t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = -1;
	p1.y = 0;
	p2.y = 0;
	p2.y = mlx->height;
	p1.color = 0xe3e6ed;
	p2.color = 0x86878c;
	while (++p1.x <= mlx->width)
	{
		p2.x = p1.x;
		draw_gradient_bresenham_line(mlx, p1, p2);
	}
}

void	lemin_draw_edges(t_info *info, t_mlx *mlx)
{
	t_point p1;
	t_point p2;
	t_edge	*edge;

	if (!info->map.map_drawed)
	{
		draw_fon(info, mlx);
		edge = info->edges;
		p1.color = 0x2d3b7f;
		p2.color = p1.color;
		while (edge)
		{
			p1.x = edge->room1->x + 50;
			p1.y = edge->room1->y + 50;
			p2.x = edge->room2->x + 50;
			p2.y = edge->room2->y + 50;
			edge = edge->next;
			draw_gradient_bresenham_line(mlx, p1, p2);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	info->map.map_drawed = 1;
}
