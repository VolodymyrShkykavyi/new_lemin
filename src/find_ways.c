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

#include <stdio.h>
#include "lemin.h"

t_edge				*get_minweight_edge(t_edge *end_edges)
{
	t_edge	*edge;
	t_edge	*best_edge;
	t_edge	*new_edge;

	edge = end_edges;
	best_edge = NULL;
	while (edge)
	{
		if (!edge->room->visited)
		{
			if (!best_edge || edge->room->weight < best_edge->room->weight)
				best_edge = edge;
			else if (edge->room->weight == best_edge->room->weight &&
					edge->room->num_edges == 2)
				best_edge = edge;
		}
		edge = edge->next;
	}
	if (!best_edge)
		return (NULL);
	MALL_CHECK(new_edge = (t_edge *)malloc(sizeof(t_edge)));
	new_edge->room = best_edge->room;
	new_edge->next = NULL;
	return (new_edge);
}


void				delete_way(t_way *way)
{
	t_edge	*edge;
	t_edge	*prev;

	way->len = 0;

	if (!way->edges)
		return ;
	edge = way->edges->next;
	while (edge)
	{
		prev = edge;
		edge = edge->next;
		prev->room->visited = 0;
		free(prev);
	}
	way->edges->next = NULL;
}

void				get_new_way(t_way *way, t_info *info)
{
	t_edge	*last_e;
	t_edge	*min_edge;

	last_e = get_last_edge(way->edges);
	last_e->room->visited = 1;
	while (1)
	{
		min_edge = get_minweight_edge(last_e->room->edges);
		if (!min_edge)
		{
			delete_way(way);
			return ;
		}
		way->len++;
		if (min_edge->room == info->start)
		{
			last_e->next = NULL;
			return ;
		}
		last_e->next = min_edge;
		last_e = min_edge;
		min_edge->room->visited = 1;
	}
}

void				find_ways(t_info *info)
{
	intmax_t		num_way;
	t_way			way_arr[info->end->num_edges];

	num_way = 0;
	info->end->visited = 1;
	info->start->visited = 0;
	while (num_way < info->end->num_edges)
	{
		MALL_CHECK(way_arr[num_way].edges = (t_edge *)malloc(sizeof(t_edge)));
		way_arr[num_way].edges->room = info->end;
		way_arr[num_way].edges->next = get_minweight_edge(info->end->edges);
		way_arr[num_way].len = 0;
		if (way_arr[num_way].edges)
			get_new_way(&(way_arr[num_way]), info);
		num_way++;
	}
	num_way = -1;
	while (++num_way < info->end->num_edges)
		if (!way_arr[num_way].len)
			get_new_way(&(way_arr[num_way]), info);
	while (--num_way >= 0)
		if (!way_arr[num_way].len)
			free(way_arr[num_way].edges);
	save_ways(&way_arr[0], info);
}
