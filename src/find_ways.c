/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:15:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/05 19:15:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static unsigned int	get_edges_num(t_room *room)
{
	t_edge			*tmp;
	unsigned int	num;

	tmp = room->edges;
	num = 0;
	while (tmp)
	{
		num++;
		tmp = tmp->next;
	}
	return (num);
}

t_way				*create_way()
{

}

int					get_shortest_ways(t_info *info, t_way *ways, int max)
{
	t_way	*tmp_w;
	t_edge	*edge;
	int 	min_w;
	int 	num_min_w;

	//room = info->end->edges;
	edge = info->end->edges;
	min_w = 0;
	while (edge)
	{
		if (edge->room->weight != -1 && (!min_w || min_w > edge->room->weight))
		{
			num_min_w = 1;
			min_w = edge->room->weight;
		}
		else if (edge->room->weight == min_w)
			num_min_w++;
		edge = edge->next;
	}
	ways = NULL;
	while (num_min_w--)
	{
		MALL_CHECK(tmp_w = (t_way *)malloc(sizeof(t_way)));
		tmp_w->next = ways;
		tmp_w->edges = NULL;
		tmp_w->edges = 0;
		ways = tmp_w;
	}
	while (min_w--)
	{

	}
}

void				find_ways(t_info *info, t_way *ways)
{
	unsigned int	max_ways;
	t_way			*shortest;

	if (get_edges_num(info->start) < get_edges_num(info->end))
		max_ways = get_edges_num(info->start);
	else
		max_ways = get_edges_num(info->end);
	get_shortest_ways(info, ways, max_ways);
}
