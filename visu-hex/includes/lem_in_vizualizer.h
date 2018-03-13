/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_vizualizer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:47:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/13 12:47:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_VIZUALIZER_H
# define LEM_IN_VIZUALIZER_H

# include "ft_mlx_image.h"
# include "../../libft/includes/libft.h"
# include <stdlib.h>

typedef struct		s_room
{
	intmax_t		x;
	intmax_t		y;
	char			ant_in;

}					t_room;

void		run_hooks(t_mlx *mlx_info);

#endif