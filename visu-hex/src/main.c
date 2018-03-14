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
/*
static void	init_info(t_info *info)
{
	info->fd = 0;
	info->ant_num = 0;
	info->num_rooms = 0;
	info->start = NULL;
	info->end = NULL;
	info->rooms = NULL;
	info->ways = NULL;
}
*/
int		main(int argc, char **argv)
{
	t_mlx	*mlx_info;
	//t_info	*info;
	void	*image;

	if (!(mlx_info = init_mlx_and_img(1024, 768, "lem_in visualization")))
	{
		ft_putstr("can't crate window\n");
		return (0);
	}
	//init_info(&info);
	run_hooks(mlx_info);

	int h = 300;
	int w = 1;

	while (h++ <= 500)
	{
		put_pixel_to_img(&mlx_info->img, h + 50, h + 50, 0xFF0000);
	}
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->img.img_ptr, 0, 0);


	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/room1_100px.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 300, 300);
	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/room2_100px.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 500, 500);




	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/room3_100px.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 200, 400);
	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/room4_100px.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 100, 100);
	image = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "img/xpm/room5_100px.xpm", &h, &w);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, image, 700, 500);

	mlx_loop(mlx_info->mlx_ptr);

}
