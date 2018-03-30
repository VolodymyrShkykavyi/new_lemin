/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 00:47:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/12 00:47:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way		*get_longest_way(t_way *arr, intmax_t size)
{
	t_way	*max_way;
	t_way	*new_way;

	max_way = NULL;
	while (--size >= 0)
	{
		if (arr[size].len > 0)
			if (!max_way || max_way->len < arr[size].len)
				max_way = &arr[size];
	}
	if (!max_way)
		return (NULL);
	MALL_CHECK(new_way = (t_way *)malloc(sizeof(t_way)));
	new_way->len = max_way->len + 1;
	new_way->next = NULL;
	new_way->edges = max_way->edges;
	max_way->len = -1;
	max_way->edges = NULL;
	return (new_way);
}

void		save_ways(t_way *way_arr, t_info *info)
{
	t_way		*longest;
	t_edge		*edge;

	info->ways = NULL;
	while (1)
	{
		longest = get_longest_way(way_arr, info->end->num_edges);
		if (!longest)
			return ;
		longest->next = info->ways;
		info->ways = longest;
		edge = info->ways->edges;
		while (edge)
		{
			edge->room->ant = 0;
			edge = edge->next;
		}
	}
}
