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

/*
** rand() % (max_number + 1 - minimum_number) + minimum_number
*/

static void	get_room_img(t_room *room)
{
	int		res;

	res = rand() % 5 + 2;
	if (res == 2)
		ft_strcpy(room->src, "visualize/img/xpm/island2_100x100.xpm");
	else if (res == 3)
		ft_strcpy(room->src, "visualize/img/xpm/island3_100x100.xpm");
	else if (res == 4)
		ft_strcpy(room->src, "visualize/img/xpm/island4_100x100.xpm");
	else if (res == 5)
		ft_strcpy(room->src, "visualize/img/xpm/island5_100x100.xpm");
	else
		ft_strcpy(room->src, "visualize/img/xpm/island6_100x100.xpm");
}

static void	save_min_max_coord(t_room *room, t_info *info)
{
	if (info->map.min_x > room->x)
		info->map.min_x = room->x;
	if (info->map.max_x < room->x)
		info->map.max_x = room->x;
	if (info->map.min_y > room->y)
		info->map.min_y = room->y;
	if (info->map.max_y < room->y)
		info->map.max_y = room->y;
}

int			parse_room(char *line, t_info *info)
{
	t_room	*room;
	char	**arr;

	MALL_CHECK(arr = ft_strsplit(line, ' '));
	MALL_CHECK(room = (t_room *)malloc(sizeof(t_room)));
	MALL_CHECK(room->name = ft_strdup(arr[0]));
	room->x = (int)ft_atoi(arr[1]) * IMG_W;
	room->y = (int)ft_atoi(arr[2]) * IMG_H;
	room->next = info->rooms;
	ft_free_2arr(arr);
	if (info->rooms == NULL)
	{
		info->map.min_x = room->x;
		info->map.max_x = room->x;
		info->map.min_y = room->y;
		info->map.max_y = room->y;
	}
	save_min_max_coord(room, info);
	info->rooms = room;
	info->num_rooms++;
	get_room_img(room);
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
