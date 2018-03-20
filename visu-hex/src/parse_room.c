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

static void	get_room_img(t_room	*room)
{
	int 	res;

	res = rand() % (6 + 1 - 2) + 2;
	if (res == 2)
		ft_strcpy(room->src, "img/xpm/island2_100x100.xpm");
	else if (res == 3)
		ft_strcpy(room->src, "img/xpm/island3_100x100.xpm");
	else if (res == 4)
		ft_strcpy(room->src, "img/xpm/island4_100x100.xpm");
	else if (res == 5)
		ft_strcpy(room->src, "img/xpm/island5_100x100.xpm");
	else
		ft_strcpy(room->src, "img/xpm/island6_100x100.xpm");
}

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
