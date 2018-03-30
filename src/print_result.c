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

int			move_ants(t_info *info)
{
	t_way	*way;
	t_edge	*edge;
	int		ret;

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

static void	print_ant_move(uintmax_t *ant, char *room_name, int *output)
{
	ft_printf("L%jd-%s", ++(*ant), room_name);
	*output = 1;
}

static int	init_params_sent_new_ants(t_info *info, uintmax_t *ant,
										intmax_t *min_len, intmax_t *delta)
{
	if (*ant >= info->ant_num)
		return (0);
	*min_len = info->ways->len;
	*delta = 0;
	return (1);
}

int			sent_new_ants(t_info *info, uintmax_t *ant, int was_output)
{
	t_way		*way;
	t_edge		*edge;
	intmax_t	min_len;
	intmax_t	delta;

	if (init_params_sent_new_ants(info, ant, &min_len, &delta) == 0)
		return (0);
	way = info->ways;
	while (way)
	{
		if (was_output)
			ft_putchar(' ');
		edge = get_last_edge(way->edges);
		if ((info->ant_num - *ant - delta + min_len >=
				(uintmax_t)(way->len + 1)) || way->len <= min_len + 1)
			print_ant_move(ant, edge->room->name, &was_output);
		else
			return (1);
		delta += way->len - min_len + 1;
		edge->room->ant = *ant;
		if (*ant == info->ant_num)
			return (1);
		way = way->next;
	}
	return (1);
}

void		print_result(t_info *info)
{
	uintmax_t	ant;
	int			ret;

	ant = 0;
	while (1)
	{
		ret = 0;
		ret += move_ants(info);
		ret += sent_new_ants(info, &ant, ret);
		if (!ret)
			return ;
		ft_putchar('\n');
	}
}
