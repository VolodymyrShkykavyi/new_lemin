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

#include "lemin.h"

void	print_error(char *str)
{
	ft_putstr("ERROR\n");
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}
