/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_rooms_coord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:46:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/27 16:46:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

static void 	decrease_len_between_change(t_info *info, int dx, int dy)
{
	t_room	*room;

	room = info->rooms;
	while (room)
	{
		room = room->next;
	}
}


static void	decrease_len_between(t_info *info)
{
	t_room	*main;
	t_room	*tmp;
	int dx;
	int dy;
	int delta;

	dx = 0;
	dy = 0;
	main = info->rooms;
	while (main->next)
	{
		tmp = main->next;
		while (tmp)
		{
			delta = ft_abs(main->x - tmp->y);
			if (!dx || dx > delta)
				dx = delta;
			delta = ft_abs(main->y - tmp->y);
			if (!dy || dy > delta)
				dy = delta;
			tmp = tmp->next;
		}
		main = main->next;
	}
	decrease_len_between_change(info, dx, dy);
}

void	scale_rooms_coord(t_info *info)
{
	t_room	*room;

	room = info->rooms;
	while (room)
	{
		if (room->x == info->map.max_x)
			room->x -= OFFSET;
		room->x -= info->map.min_x - OFFSET;
		room->y -= info->map.min_y - OFFSET;
		room = room->next;
	}
	info->map.max_x -= info->map.min_x - OFFSET;
	info->map.max_y -= info->map.min_y - OFFSET;
	info->map.min_y = OFFSET;
	info->map.min_x = OFFSET;
	decrease_len_between(info);
}
