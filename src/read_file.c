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
/*	if (is_command_support(*line))
	{
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
	}
	else
		return (0);*/
	if (ft_strcmp("##start", *line) == 0)
	{
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		if (info->start)
			return (1);
		if (parse_room(*line, info))
		{
			ft_printf("supported command error parse room\n");
			return (1);
		}
		ft_printf("{start command}\n");
		info->start = info->rooms;
		info->start->weight = 1;
	}
	else if (ft_strcmp("##end", *line) == 0)
	{
		ft_strdel(line);
		if (get_next_line(info->fd, line) <= 0)
			print_error("can't read file");
		if (info->end)
		{
			ft_printf("multi_end\n");
			return (1);
		}
		ft_printf("{end command}\n");
		if (parse_room(*line, info))
		{
			ft_printf("supported command error parse room\n");
			return (1);
		}
		info->end = info->rooms;
		info->end->weight = 1;
	}
	return (0);
}

static int	parse_line(char **line, t_info *info, int *room_parsed)
{
	if (is_comment(*line))
	{
		ft_printf("comment - ");
		return (0);
	}
	else if (is_command(*line))
	{
		ft_printf("command - ");
		return (parse_command(line, info));
	}
	else if (!(*room_parsed) && is_room(*line))
	{
		ft_printf("room parse - ");
		return (parse_room(*line, info));
	}
	else if (is_edge(*line))
	{
		ft_printf("edge - ");
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
			ft_printf("some read error in %s\n", line);
			ft_strdel(&line);
			break;
		}
		if (is_command_support(line))
			num_lines++;
		num_lines++;
		ft_printf("line: %s\n", line);
		ft_strdel(&line);
	}
	close(info->fd);
	return (num_lines);
}
