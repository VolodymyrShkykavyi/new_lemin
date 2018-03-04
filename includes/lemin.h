/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:27:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/15 20:27:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_edge
{
	struct s_room	*room;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	t_edge			*edges;
	struct s_room	*next;
}					t_room;

typedef struct	s_info
{
	int 		fd;
	uintmax_t	ant_num;
	t_room		*rooms;
	t_room		*start;
	t_room		*end;
}				t_info;

/*
** returns the number of read lines
*/

uintmax_t	read_file(t_info *info);
void	print_error(char *text);
int 	is_command(char *str);
int 	is_room(char *str);
int 	is_edge(char *str);
int		is_comment(char *str);
int		is_command_support(char *str);
#endif