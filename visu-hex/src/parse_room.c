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

#include "lem_in_vizualizer.h"

int			parse_room(char *line, t_info *info)
{
	t_room	*room;
	char	**arr;

	MALL_CHECK(arr = ft_strsplit(line, ' '));
	MALL_CHECK(room = (t_room *)malloc(sizeof(t_room)));
	MALL_CHECK(room->name = ft_strdup(arr[0]));
	room->x = (int)ft_atoi(arr[1]);
	room->y = (int)ft_atoi(arr[2]);
	room->next = info->rooms;
	ft_free_2arr(arr);
	info->rooms = room;
	info->num_rooms++;
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
