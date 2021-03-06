/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 01:25:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/09 01:25:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rgb_get_color(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0)
		return (0);
	r = (r > 0xFF) ? 0xFF : r;
	g = (g > 0xFF) ? 0xFF : g;
	b = (b > 0xFF) ? 0xFF : b;
	return (r * 0x010000 + g * 0x0100 + b);
}
