/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 20:44:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/04 20:44:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	init_info(int fd, t_info *info)
{
	info->fd = fd;
	info->ant_num = 0;
	info->num_rooms = 0;
	info->start = NULL;
	info->end = NULL;
	info->rooms = NULL;
	info->ways = NULL;
}

int		main(int argc, char **argv)
{
	int			fd;
	t_info		info;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc == 1)
		fd = 0;
	else
	{
		ft_printf("Usage:\n\t%s < <file_name>\n\t%s <file_name>\n", argv[0], argv[0]);
		return (0);
	}
	init_info(fd, &info);
	read_file(&info);
	valid_and_set_weight(&info);
	find_ways(&info);
	if (DEBUG)
	{
		print_rooms(&info);
		ft_putchar_fd('\n', 2);
		print_ways(info.ways);
		ft_putchar_fd('\n', 2);
	}
	print_result(&info);
	return (0);
}
