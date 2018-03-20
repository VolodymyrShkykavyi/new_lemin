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

#include <stdio.h>
#include "lemin.h"

uintmax_t	set_weight_list(t_room ***list, uintmax_t num)
{
	uintmax_t	num_next;
	uintmax_t	i;
	t_room		**new_list;
	t_edge		*edge;

	num_next = 0;
	MALL_CHECK(new_list = (t_room **)malloc(sizeof(t_room *) * (num + 1)));
	i = 0;
	num = 0;
	while ((*list)[i])
	{
		edge = (*list)[i]->edges;
		while (edge)
		{
			if (!edge->room->weight)
			{
				edge->room->weight = (*list)[i]->weight + 1;
				if (edge->room->num_edges > 1)
				{
					num_next += edge->room->num_edges - 1;
					new_list[num++] = edge->room;
				}
				else
					edge->room->visited = 1;
			}
			edge = edge->next;
		}
		i++;
	}
	new_list[num] = NULL;
	free(*list);
	*list = new_list;
	return (num_next);
}

void		set_weight(t_info *info)
{
	t_room	**start_list;
	uintmax_t	num_start_next;

	MALL_CHECK(start_list = (t_room **)malloc(sizeof(t_room *) * 2));
	start_list[0] = info->start;
	start_list[1] = NULL;
	num_start_next = set_weight_list(&start_list, info->start->num_edges);
	while (1)
	{
		if (!(num_start_next = set_weight_list(&start_list, num_start_next)))
		{
			free(start_list);
			break ;
		}
	}
}

void		valid_and_set_weight(t_info *info)
{
	if (!info->start || !info->end || !info->start->edges || !info->end->edges)
		print_error("can't find start/end pos");
	info->end->visited = 0;
	info->start->weight = 1;
	set_weight(info);
	if (info->end->weight == 0)
		print_error("no way from start to end");
}
