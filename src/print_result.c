/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 01:16:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/12 01:16:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int 	move_ants(t_info *info)
{
	t_way	*way;
	t_edge	*edge;
	int 	ret;

	ret = 0;
	way = info->ways;
	while (way)
	{
		edge = way->edges;
		while (edge)
		{
			if (edge->next && edge->next->room->ant)
			{
				if (ret != 0)
					ft_putchar(' ');
				ft_printf("L%jd-%s", edge->next->room->ant, edge->room->name);
				edge->room->ant = edge->next->room->ant;
				edge->next->room->ant = 0;
				ret = 1;
			}
			edge = edge->next;
		}
		way = way->next;
	}
	return (ret);
}

int 	sent_new_ants(t_info *info, uintmax_t *ant)
{
	t_way		*way;
	t_edge		*edge;
	uintmax_t	min_len;

	if (*ant >= info->ant_num)
		return (0);
	way = info->ways;
	min_len = way->len;
	min_len--;
	while (way)
	{
		(*ant)++;
		if (*ant != 1)
			ft_putchar(' ');
		edge = get_last_edge(way->edges);
		ft_printf("L%jd-%s", *ant, edge->room->name);
		edge->room->ant = *ant;
		if (*ant >= info->ant_num)
			return (1);
		way = way->next;
	}
	return (1);
}

void	print_result(t_info *info)
{
	uintmax_t	ant;
	int 		ret;

	ant = 0;
	while (1)
	{
		ret = 0;
		ret += move_ants(info);
		ret += sent_new_ants(info, &ant);
		if (!ret)
			return ;
		ft_putchar('\n');
	}
}
