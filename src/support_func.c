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
	if (!str || !(*(str + 1)))
		return (0);
	if (*str == '#' && *(str + 1) != '#')
		return (1);
}

int 	is_edge(char *str)
{
	int		edge;

	if (!str)
		return (0);
	if (*str == '#' || *str == '-')
		return (0);
	while (*str && *str != '-')
		str++;
	if (!(*str))
		return (0);
	str++;
	while (*str || *str != '-')
		str++;
	if (!(*str))
		return (1);
	return (0);
}

int 	is_room(char *str)
{
	if (!str)
		return (0);
	if (*str == '#')
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
	while (*str && ft_isdigit(*str))
		str++;
	if (!(*str))
		return (1);
	return (0);
}

int 	is_command(char *str)
{
	if (ft_strncmp(str, "##", 2) == 0)
		return (1);
	return (0);
}

int		is_command_support(char *str)
{
	if (ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0)
		return (1);
	return (0);
}