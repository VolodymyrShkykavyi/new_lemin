/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:41:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/04 22:41:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_comment(char *str)
{
	if (!str || !str[1])
		return (0);
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

int		is_edge(char *str)
{
	if (!str)
		return (0);
	if (*str == '#' || *str == '-')
		return (0);
	while (*str && *str != '-')
		str++;
	if (!(*str))
		return (0);
	str++;
	while (*str && *str != '-')
		str++;
	if (!(*str))
		return (1);
	return (0);
}

int		is_room(char *str)
{
	if (!str)
		return (0);
	if (*str == '#' || *str == 'L')
		return (0);
	while (*str && *str != ' ')
		str++;
	if (!(*str))
		return (0);
	str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (!(*str) || *str != ' ')
		return (0);
	str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (!(*str))
		return (1);
	return (0);
}

int		is_command(char *str)
{
	if (ft_strncmp(str, "##", 2) == 0)
		return (1);
	return (0);
}

t_edge				*get_last_edge(t_edge *edges)
{
	t_edge	*edge;
	edge = edges;
	while (edge && edge->next)
		edge = edge->next;
	return (edge);
}
