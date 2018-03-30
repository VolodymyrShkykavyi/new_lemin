/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:46:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/13 12:46:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

int 		hook_close(void)
{
	exit (0);
}

int		pressed_key(int key, t_all *all)
{
	if (key == 53)
		exit(0);
	else if (key == 48)
	{
		all->info->map.print_name = (all->info->map.print_name) ? 0 : 1;
		lemin_draw_edges(all->info, all->mlx);
		lemin_draw_rooms(all->info, all->mlx);
		if (all->ant_step)
		{
			all->ant_step--;
			ant_move(all);
		}
	}
	else if (key == 49)
	{
		ant_move(all);
	}
	printf("key = %d\n", key);
	return (0);
}

void		init_ants(t_all *all)
{
	uintmax_t	num;
	t_ant		*ant;

	num = all->info->ants;
	while (num--)
	{
		MALL_CHECK((ant = (t_ant *)malloc(sizeof(t_ant))));
		ant->x = all->info->start->x;
		ant->y = all->info->start->y;
		ant->dest = NULL;
		ant->name = num + 1;
		ant->next = all->ants;
		all->ants = ant;
	}
}

void		run_hooks(t_mlx *mlx_info, t_info *info)
{
	static t_all	all;

	all.info = info;
	all.mlx = mlx_info;
	all.ant_step = 0;
	all.ants = NULL;
	all.fd = open("ant_moves.txt", O_RDONLY);
	if (all.fd < 0)
		print_error("can't open file with ant moves\n");
	init_ants(&all);
	mlx_hook(mlx_info->win_ptr, 17, 0, &hook_close, NULL);
	mlx_hook(mlx_info->win_ptr, 2, 3, &pressed_key, &all);
}
