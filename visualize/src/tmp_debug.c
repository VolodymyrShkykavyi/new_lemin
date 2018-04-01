/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:16:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/05 13:16:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"
#include <stdio.h>

void	print_rooms(t_info *info)
{
	t_room *room;

	room = info->rooms;
	dprintf(2, "rooms:\n");
	while (room)
	{
		if (room == info->start)
			dprintf(2, "%-19s", "\033[32m*start*\033[0m");
		else if (room == info->end)
			dprintf(2, "%-19s", "\033[33m*end*\033[0m");
		else
			dprintf(2, "%10c", ' ');
		dprintf(2, "name: %-20s |x: %-3jd |y: %-3jd | map: %s\n", room->name,
		room->x, room->y, room->src + 8);
		dprintf(2, "\033[0m");
		room = room->next;
	}
}

void	print_edges(t_info *info)
{
	t_edge	*edge;

	edge = info->edges;
	while (edge)
	{
		dprintf(2, "{[%s] - [%s]}\n", edge->room1->name, edge->room2->name);
		edge = edge->next;
	}
}
