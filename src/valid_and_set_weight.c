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
	if (!tmp_edge->next)
	{
		if (room->weight != 1)
			room->weight = -1;
		return ;
	}
	while (tmp_edge)
	{
		if (!tmp_edge->room->weight ||
				tmp_edge->room->weight > room->weight + 1)
			tmp_edge->room->weight = room->weight + 1;
		tmp_edge = tmp_edge->next;
	}
	tmp_edge = room->edges;
	while (tmp_edge)
	{
		set_weight(tmp_edge->room);
		tmp_edge = tmp_edge->next;
	}
}

void 	valid_and_set_weight(t_info *info)
{
	t_edge	*tmp_edge;

	if (!info->start || !info->end || !info->start->edges || !info->end->edges)
		print_error("can't find start/end pos");
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
