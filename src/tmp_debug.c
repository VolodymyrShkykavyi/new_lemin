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
			printf("*start* ");
		else if (room == info->end)
			printf("*end* ");
		printf("name: %s,\t\tx: %d, y: %d, weight: %d\n\tedges{", room->name, room->x, room->y, room->weight);
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