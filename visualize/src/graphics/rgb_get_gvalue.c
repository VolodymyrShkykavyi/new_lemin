/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_get_gvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 01:09:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/09 01:09:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	rgb_get_gvalue(int color)
{
	return ((color & 0xFF00) / 0x0100);
}
