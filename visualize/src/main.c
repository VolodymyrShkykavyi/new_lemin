/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:12:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/13 12:12:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "lem_in_vizualizer.h"

static void	init_info(t_info *info)
{
	info->start = NULL;
	info->end = NULL;
	info->rooms = NULL;
	info->edges = NULL;
	info->num_rooms = 0;
	info->ants = 0;
	info->map.print_name = 1;
	info->map.map_drawed = 0;
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx_info;
	t_info	info;
	void	*image;


	init_info(&info);
	read_data(&info);
	scale_rooms_coord(&info);

	//printf("ant num: %jd\n", info.ants);
	//print_rooms(&info);
	//print_edges(&info);
	//printf("min_x: %jd\tmin_y:%jd\nmax_x: %jd\tmax_y: %jd\n", info.map.min_x,
	//			info.map.min_y, info.map.max_x, info.map.max_y);

	if (!(mlx_info = init_mlx_and_img(info.map.max_x + IMG_W, info.map.max_y + IMG_H, "lem_in visualization")))
	{
		ft_putstr("can't crate window\n");
		return (0);
	}
	run_hooks(mlx_info, &info);
	lemin_draw_edges(&info, mlx_info);
	lemin_draw_rooms(&info, mlx_info);
	mlx_loop(mlx_info->mlx_ptr);
}
