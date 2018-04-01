/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_draw_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:58:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/04/01 15:58:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

static int	get_delta_px(intmax_t dest, intmax_t pos, int speed)
{
	int	delta;

	delta = (int)(dest - pos);
	if (ft_abs(delta) > speed)
	{
		if (delta > 0)
			return (speed);
		else
			return (-speed);
	}
	return (delta);
}

static void	get_ant_pos(t_ant *ant, t_all *all)
{
	int error;
	int	dx;
	int	dy;
	int dirx;
	int diry;

	dx = ft_abs((int)(ant->x - ant->dest->x));
	dy = ft_abs((int)(ant->y - ant->dest->y));
	dirx = get_delta_px(ant->dest->x, ant->x, all->speed);
	dirx = (dy != 0 && dx < dy) ? (int)(dirx * ((double)dx / dy)) : dirx;
	diry = get_delta_px(ant->dest->y, ant->y, all->speed);
	diry = (dx != 0 && dy < dx) ? (int)(diry * ((double)dy / dx)) : diry;
	error = ft_abs(dx) - ft_abs(dy);
	if (error * 2 > -dy && ant->x != ant->dest->x)
	{
		error -= dy;
		ant->x += dirx;
	}
	if (error * 2 < dx && ant->y != ant->dest->y)
		ant->y += diry;
	ant->img = (ant->x > ant->dest->x) ? all->img_ant_left : all->img_ant_right;
}

static int	check_moves(t_all *all, char ***moves)
{
	int h;
	int w;

	if (!*moves)
	{
		*moves = get_new_moves(all);
		if (!*moves)
			return (0);
	}
	return (1);
}

/*
** just for "The Norm" =(
*/

static void	rewrite_ant_moves(t_all *all, char ***moves)
{
	ft_free_2arr(*moves);
	*moves = get_new_moves(all);
}

int			draw_ants(t_all *all, int move_ant)
{
	int				i;
	int				ant_in_way;
	t_ant			*ant;
	static char		**moves = NULL;

	if (check_moves(all, &moves) == 0)
		return (0);
	ant_in_way = 0;
	i = -1;
	while ((moves)[++i])
	{
		ant = find_ant(all, (uintmax_t)ft_atoi(&moves[i][1]));
		if (ant->x != ant->dest->x || ant->y != ant->dest->y)
		{
			if (move_ant)
				get_ant_pos(ant, all);
			ant_in_way = 1;
		}
		if (ant->img)
			mlx_put_image_to_window(all->mlx->mlx_ptr,
				all->mlx->win_ptr, ant->img, (int)ant->x, (int)ant->y);
	}
	if (!ant_in_way)
		rewrite_ant_moves(all, &moves);
	return (1);
}
