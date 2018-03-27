/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:26:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/04 22:26:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_vizualizer.h"

void	print_error(char *str)
{

	ft_putstr("ERROR\n");
	/*fd = open("log.txt", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
		close(fd);
	}*/
	ft_putendl_fd(str, 2);
	exit(0);
}
