/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:30:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/31 17:30:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

t_ant	*find_ant(t_all *all, uintmax_t name)
{
	t_ant	*ant;

	ant = all->ants;
	if (name > all->info->ants)
		return (NULL);
	while (ant)
	{
		if (ant->name == name)
			return (ant);
		ant = ant->next;
	}
	return (NULL);
}
