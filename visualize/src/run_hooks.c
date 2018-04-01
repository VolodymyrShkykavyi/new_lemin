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

int			hook_close(void)
{
	exit(0);
}

void		draw_speed_info(t_all *all)
{
	char	*str;

	str = ft_itoa_base(all->speed, 10);
	mlx_string_put(all->mlx->mlx_ptr, all->mlx->win_ptr,
				all->mlx->width - 150, 0, 0xFF0000, "speed:");
	mlx_string_put(all->mlx->mlx_ptr, all->mlx->win_ptr,
				all->mlx->width - 75, 0, 0xFF0000, str);
	free(str);
}

/*
** keys:
** 48 - Tab
** 49 - space
** 53 - esc
** 69 - '+'
** 78 - '-'
*/

int			pressed_key(int key, t_all *all)
{
	if (key == 53)
		exit(0);
	else if (key == 48)
	{
		all->info->map.print_name = (all->info->map.print_name) ? 0 : 1;
		redraw_all(all);
	}
	else if (key == 49)
	{
		ant_move(all);
	}
	else if (key == 69 || key == 78)
	{
		if (key == 69)
			all->speed++;
		else
			(all->speed > 1) ? all->speed-- : 1;
		redraw_all(all);
		draw_speed_info(all);
	}
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
	int 			h;
	int 			w;

	all.info = info;
	all.mlx = mlx_info;
	all.ant_step = 0;
	all.ants = NULL;
	all.speed = 10;
	all.img_ant_left =  mlx_xpm_file_to_image(all.mlx->mlx_ptr,
						"visualize/img/xpm/ant_go_left_70px.xpm", &h, &w);
	all.img_ant_right =  mlx_xpm_file_to_image(all.mlx->mlx_ptr,
						"visualize/img/xpm/ant_go_right_70px.xpm", &h, &w);
	all.fd = open("ant_moves.txt", O_RDONLY);
	if (all.fd < 0)
		print_error("can't open file with ant moves\n");
	init_ants(&all);
	mlx_hook(mlx_info->win_ptr, 17, 0, &hook_close, NULL);
	mlx_hook(mlx_info->win_ptr, 2, 3, &pressed_key, &all);
}
