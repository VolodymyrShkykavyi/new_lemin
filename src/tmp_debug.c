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

#include "lemin.h"

void		print_rooms(t_info *info)
{
	t_room *room;
	t_edge *edge;

	room = info->rooms;
	dprintf(2, "\nrooms:\n");
	while (room)
	{
		if (room == info->start)
			dprintf(2, "%-19s", "\033[32m*start*\033[0m");
		else if (room == info->end)
			dprintf(2, "%-19s", "\033[33m*end*\033[0m");
		else
			dprintf(2, "%10c", ' ');
		dprintf(2, "name: %-20s |x: %-3d |y: %-3d |weight: %-4d "
		"|edge_num: %-5d edges{", room->name, room->x, room->y,
			room->weight, room->num_edges);
		edge = room->edges;
		while (edge)
		{
			dprintf(2, "[%s(%d)] ", edge->room->name, edge->room->weight);
			edge = edge->next;
		}
		dprintf(2, "}\n\033[0m");
		room = room->next;
	}
}

void		print_ways(t_way *ways)
{
	t_way	*way;
	t_edge	*edge;

	way = ways;
	while (way)
	{
		edge = way->edges;
		while (edge)
		{
			dprintf(2, "{%s}", edge->room->name);
			edge = edge->next;
			if (edge)
				dprintf(2, " -> ");
		}
		dprintf(2, " | len: %jd\n", way->len);
		way = way->next;
	}
}
