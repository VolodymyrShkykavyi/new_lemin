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


void				find_ways(t_info *info, t_way *ways)
{
	unsigned int	max_ways;


	if (get_edges_num(info->start) < get_edges_num(info->end))
		max_ways = get_edges_num(info->start);
	else
		max_ways = get_edges_num(info->end);


}
