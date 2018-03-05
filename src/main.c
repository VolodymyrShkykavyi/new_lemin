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
	info->start = NULL;
	info->end = NULL;
	info->rooms = NULL;
}

int		main(int argc, char **argv)
{
	int			fd;
	t_info		info;
	uintmax_t	lines;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	init_info(fd, &info);
	lines = read_file(&info);
	print_rooms(&info);
	valid_and_set_weight(&info);
}
