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
#include <stdio.h>
void 	print_rooms(t_info *info)
{
	t_room *room;
	t_edge *edge;

	room = info->rooms;
	printf("rooms:\n");
	while (room)
	{
		if (room == info->start)
			printf("%-19s", "\033[32m*start*\033[0m");
		else if (room == info->end)
			printf("%-19s", "\033[33m*end*\033[0m");
		else
			printf("%10c", ' ');
		if (room->num_edges <= 1 && room != info->start && room != info->end)
			printf("\033[31m");
		printf("name: %-20s |x: %-3d |y: %-3d |weight: %-4d |edge_num: %-5d edges{", room->name, room->x, room->y,
			   room->weight, room->num_edges);
		edge = room->edges;
		while (edge)
		{
			printf("[%s(%d)] ", edge->room->name, edge->room->weight);
			edge = edge->next;
		}
		printf("}\n");
		printf("\033[0m");
		room = room->next;
	}

}

void	print_ways(t_way *ways)
{
	t_way	*way;
	t_edge	*edge;

	way = ways;
	while (way)
	{
		edge = way->edges;
		while (edge)
		{
			printf("{%s}", edge->room->name);
			edge = edge->next;
			if (edge)
				printf(" -> ");
		}
		printf(" | len: %jd\n", way->len);
		way = way->next;
	}
}