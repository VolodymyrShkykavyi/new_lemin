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
		printf("name: %-20s\t|x: %-3d\t|y: %-3d\t|weight: %-3d\tedges{", room->name, room->x, room->y, room->weight);
		edge = room->edges;
		while (edge)
		{
			printf("[%s] ", edge->room->name);
			edge = edge->next;
		}
		printf("}\n");
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
		printf("\n");
		way = way->next;
	}
}