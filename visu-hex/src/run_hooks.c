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

int		pressed_key(int key, void *info)
{
	if (key == 53)
		exit(0);
	return (0);
}

void		run_hooks(t_mlx *mlx_info)
{
	mlx_hook(mlx_info->win_ptr, 17, 0, &hook_close, NULL);
	mlx_hook(mlx_info->win_ptr, 2, 3, &pressed_key, NULL);
}
