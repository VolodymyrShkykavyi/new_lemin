/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 00:55:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/05 00:55:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	save_edge(t_room *dest, t_room *link)
{
	t_edge	*edge;

	edge = dest->edges;
	while (edge)
	{
		if (edge->room == link)
			return (0);
		edge = edge->next;
	}
	MALL_CHECK(edge = malloc(sizeof(t_edge)));
	edge->next = dest->edges;
	edge->room = link;
	dest->edges = edge;
	return (0);
}

int			parse_edge(char *line, t_info *info)
{
	t_room	*room1;
	t_room	*room2;
	char	**arr;

	MALL_CHECK(arr = ft_strsplit(line, '-'));
	if (!(arr[0]) || !(arr[1]) || arr[2])
	{
		ft_free_2arr(arr);
		return (1);
	}
	room1 = find_room(arr[0], info);
	room2 = find_room(arr[1], info);
	ft_free_2arr(arr);
	if (!room1 || !room2 || room1 == room2)
		return (2);
	if (save_edge(room1, room2) || save_edge(room2, room1))
		return (3);
	return (0);
}
