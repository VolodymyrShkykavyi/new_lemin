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
/*
static void	set_weight(t_room *room, t_info *info)
{
	t_edge	*tmp_edge;

	if (!room)
		return ;
	tmp_edge = room->edges;
	room->visited = 1;
	//printf("in %s\n", room->name);
	while (tmp_edge)
	{
		if (!tmp_edge->room->weight ||
				tmp_edge->room->weight > room->weight + 1)
		{
			tmp_edge->room->weight = room->weight + 1;
			//tmp_edge->room->visited = 0;
		}
		if (tmp_edge->room->visited == 0)
			set_weight(tmp_edge->room, info);
		tmp_edge = tmp_edge->next;
	}
	if (room == info->end)
		return ;
}
*/

uintmax_t	set_weight_list(t_room ***list, uintmax_t num)
{
	uintmax_t	num_next;
	uintmax_t	i;
	t_room		**new_list;
	t_edge		*edge;

//	ft_putstr("in set weight_list\n");
	num_next = 0;
	MALL_CHECK(new_list = (t_room **)malloc(sizeof(t_room *) * (num + 1)));
	i = 0;
	num = 0;
	while ((*list)[i])
	{
//		ft_putstr("room set\n");
		printf("room(#%jd): %s, ", i, (*list)[i]->name);
		edge = (*list)[i]->edges;
		(*list)[i]->visited = 1;
		while (edge)
		{
			if (edge->room->visited != 1 && !edge->room->weight)
			{
				printf("{%s}, ", edge->room->name);

				if (edge->room->num_edges > 1)
				{
					edge->room->weight = (*list)[i]->weight + 1;
					num_next += edge->room->num_edges - 1;
					new_list[num++] = edge->room;
				}/*
				else
				{
					free(edge->room->edges);
					edge->room->edges = NULL;
				}*/
			}
			edge = edge->next;
		}
		printf("\n");
		i++;
	}
	new_list[num] = NULL;
	free(*list);
	*list = new_list;
	printf("next edge num: %jd\n", num_next);
	return (num_next);
}

void		set_weight(t_info *info)
{
	t_room	**start_list;
	t_room	**end_list;
	uintmax_t	num_start_next;
	uintmax_t	num_end_next;

	MALL_CHECK(start_list = (t_room **)malloc(sizeof(t_room *) * 2));
	MALL_CHECK(end_list = (t_room **)malloc(sizeof(t_room *) * 2));
	start_list[0] = info->start;
	start_list[1] = NULL;
	end_list[0] = info->end;
	end_list[1] = NULL;
	num_start_next = set_weight_list(&start_list, info->start->num_edges);
	while (1)
	{
		if (!(num_start_next = set_weight_list(&start_list, num_start_next)))
			break ;
		//set_weight_list(&end_list, info->end->num_edges);
		/*if (1)
			break;*/
	}
}

void		valid_and_set_weight(t_info *info)
{
	t_edge	*tmp_edge;

	print_rooms(info);
	if (!info->start || !info->end || !info->start->edges || !info->end->edges)
		print_error("can't find start/end pos");
	info->end->visited = 0;
	info->start->weight = 1;

	set_weight(info);
	tmp_edge = info->end->edges;
	while (tmp_edge)
	{
		if (tmp_edge->room->weight)
			return ;
		tmp_edge = tmp_edge->next;
	}
	//print_error("no way from start to end");
}
