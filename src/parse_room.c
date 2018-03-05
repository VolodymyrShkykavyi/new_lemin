/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:54:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/04 23:54:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_room_info(t_room *room, t_info *info)
{
	t_room	*tmp;

	tmp = info->rooms;
	while (tmp)
	{
		if (ft_strcmp(room->name, tmp->name) == 0)
			return (1);
		if (tmp->x == room->x && tmp->y == room->y)
			return (2);
		tmp = tmp->next;
	}
	return (0);
}

int			parse_room(char *line, t_info *info)
{
	t_room	*room;
	char	**arr;

	MALL_CHECK(arr = ft_strsplit(line, ' '));
	if (!arr[0] || !arr[1] || !arr[2] || arr[3])
	{
		ft_printarr(arr);
		ft_free_2arr(arr);
		return (2);
	}
	MALL_CHECK(room = (t_room *)malloc(sizeof(t_room)));
	MALL_CHECK(room->name = ft_strdup(arr[0]));
	room->x = (int)ft_atoi(arr[1]);
	room->y = (int)ft_atoi(arr[2]);
	room->next = info->rooms;
	room->edges = NULL;
	room->weight = 0;
	room->visited = 0;
	ft_free_2arr(arr);
	if (check_room_info(room, info))
		return (3);
	info->rooms = room;
	return (0);
}

t_room		*find_room(char *name, t_info *info)
{
	t_room	*tmp;

	tmp = info->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
