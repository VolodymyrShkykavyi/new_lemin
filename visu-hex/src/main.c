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
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx_info;
	t_info	info;
	void	*image;


	init_info(&info);
	read_data(&info);


	//printf("ant num: %jd\n", info.ants);
	print_rooms(&info);
	//print_edges(&info);
	printf("min_x: %jd\tmin_y:%jd\nmax_x: %jd\tmax_y: %jd\n", info.map.min_x,
				info.map.min_y, info.map.max_x, info.map.max_y);




	if (!(mlx_info = init_mlx_and_img(1024, 768, "lem_in visualization")))
	{
		ft_putstr("can't crate window\n");
		return (0);
	}
	run_hooks(mlx_info);
	t_room *room;
	int h, w;
	room = info.rooms;
	while (room)
	{
		image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, room->src, &h, &w);
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, room->x, room->y);

		room = room->next;
	}
	mlx_loop(mlx_info->mlx_ptr);
/*
	int h = 300;
	int w = 1;

	while (h++ <= 500)
	{
		put_pixel_to_img(&mlx_info->img, h + 50, h + 50, 0xFF0000);
	}
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->img.img_ptr, 0, 0);


	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island1_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 300, 300);
	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island2_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 500, 500);




	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island3_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 200, 400);


	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island4_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 100, 100);
	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island5_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 700, 500);

	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island6_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 400, 500);

	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/island7_100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 700, 600);


	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/ant_wait100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 700, 450);

	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/ant_go_right100x100.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 450, 400);

	//mlx_loop(mlx_info->mlx_ptr);
*/
}
