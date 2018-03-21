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

#include "lem_in_vizualizer.h"

static int	save_edge(t_info *info, t_room *r1, t_room *r2)
{
	t_edge	*tmp;

	tmp = info->edges;
	while (tmp)
	{
		if ((r1 == tmp->room1 && r2 == tmp->room2) ||
				(r1 == tmp->room2 && r2 == tmp->room1))
			return (0);
		tmp = tmp->next;
	}
	MALL_CHECK(tmp = (t_edge *)malloc(sizeof(t_edge)));
	tmp->next = info->edges;
	tmp->room1 = r1;
	tmp->room2 = r2;
	info->edges = tmp;
	return (0);
}

int			parse_edge(char *line, t_info *info)
{
	t_room	*room1;
	t_room	*room2;
	char	**arr;

	MALL_CHECK(arr = ft_strsplit(line, '-'));
	room1 = find_room(arr[0], info);
	room2 = find_room(arr[1], info);
	ft_free_2arr(arr);
	if (!room1 || !room2 || room1 == room2)
		return (2);
	save_edge(info, room1, room2);
	return (0);
}
