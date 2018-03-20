/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:36:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/04 22:36:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		get_ant_num(t_info *info)
{
	char	*line;

	get_next_line(info->fd, &line);
	info->ant_num = (uintmax_t)ft_atoi(line);
	ft_strdel(&line);
}

int			parse_command(char **line, t_info *info)
{

	if (ft_strcmp("##start", *line) == 0)
	{
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		info->start = info->rooms;
	}
	else if (ft_strcmp("##end", *line) == 0)
	{
		ft_putendl(*line);
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		if (info->end)
			return (1);
		if (!is_room(*line) || parse_room(*line, info))
			return (1);
		info->end = info->rooms;
	}
	return (0);
}

static int	parse_line(char **line, t_info *info)
{
	if (is_comment(*line))
		return (0);
	else if (is_command(*line))
		return (parse_command(line, info));
	else if (is_room(*line))
		return (parse_room(*line, info));
	else if (is_edge(*line))
		return (parse_edge(*line, info));
	else
		return (1);
}

void	read_data(t_info *info)
{
	char		*line;
	int			ret;

	get_ant_num(info);
	while ((ret = get_next_line(info->fd, &line)))
	{
		if (ret < 0)
			print_error("can't read data");
		if (strcmp(line, "ERROR") == 0)
			exit(0);
		if (parse_line(&line, info, &room_parsed))
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
}