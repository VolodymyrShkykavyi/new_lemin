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

void	get_ant_num(t_info *info, uintmax_t *num_lines)
{
	int 	ret;
	char	*line;

	while ((ret = get_next_line(info->fd, &line)))
	{
		if (ret < 0)
			print_error("can't read file");
		if (is_comment(line))
		{
			(*num_lines)++;
			ft_strdel(&line);
		}
		else
			break;
	}
	ret = 0;
	while (line[ret])
		if (!ft_isdigit(line[ret++]))
			print_error("wrong ant num");
	info->ant_num = ft_atoi(line);
	if (!(info->ant_num))
		print_error("wrong ant num");
	ft_strdel(&line);
	(*num_lines)++;
}

int 		parse_command(char **line, t_info *info)
{
	if (is_command_support(*line))
	{
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		if (parse_room(*line, info))
			return (1);
	}
	if (ft_strcmp("##start", *line) == 0)
	{
		if (info->start)
			return (1);
		info->start = info->rooms;
	}
	else if (ft_strcmp("##end", *line) == 0)
	{
		if (info->end)
			return (1);
		info->end = info->rooms;
	}
	return (0);
}

static int	parse_line(char **line, t_info *info, int *room_parsed)
{
	if (is_comment(*line))
		return (0);
	else if (is_command(*line))
		return (parse_command(line, info));
	else if (!(*room_parsed) && is_room(*line))
		return (parse_room(*line, info));
	else if (is_edge(*line))
	{
		*room_parsed = 1;
		return (parse_edge(*line, info));
	}
	else
		return (1);
}

uintmax_t	read_file(t_info *info)
{
	uintmax_t	num_lines;
	char		*line;
	int 		ret;
	int 		room_parsed;

	num_lines = 0;
	room_parsed = 0;
	get_ant_num(info, &num_lines);
	while ((ret = get_next_line(info->fd, &line)))
	{
		if (ret < 0)
			print_error("can't read file");
		if (parse_line(&line, info, &room_parsed))
		{
			ft_strdel(&line);
			break;
		}
		if (is_command_support(line))
			num_lines++;
		num_lines++;
		ft_strdel(&line);
	}
	close(info->fd);
	return (num_lines);
}
