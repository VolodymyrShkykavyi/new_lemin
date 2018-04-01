/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:03:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/04/01 17:03:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

void		redraw_all(t_all *all)
{
	lemin_draw_edges(all->info, all->mlx);
	lemin_draw_rooms(all->info, all->mlx);
	draw_ants(all, 0);
}
