/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_set_weight.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:32:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/05 01:32:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	set_weight(t_room *room)
{
	t_edge	*tmp_edge;

	if (!room)
		return ;
	tmp_edge = room->edges;
	room->visited = 1;
	while (tmp_edge)
	{
		if (!tmp_edge->room->weight ||
				tmp_edge->room->weight > room->weight + 1)
		{
			tmp_edge->room->weight = room->weight + 1;
			tmp_edge->room->visited = 0;
		}
		if (tmp_edge->room->visited == 0)
			set_weight(tmp_edge->room);
		tmp_edge = tmp_edge->next;
	}
}

void		valid_and_set_weight(t_info *info)
{
	t_edge	*tmp_edge;

	if (!info->start || !info->end || !info->start->edges || !info->end->edges)
		print_error("can't find start/end pos");
	info->end->visited = 0;
	info->start->weight = 1;
	set_weight(info->start);
	tmp_edge = info->end->edges;
	while (tmp_edge)
	{
		if (tmp_edge->room->weight)
			return ;
		tmp_edge = tmp_edge->next;
	}
	print_error("no way from start to end");
}
