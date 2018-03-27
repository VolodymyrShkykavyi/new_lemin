/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:40:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 16:40:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_IMAGE_H
# define FT_MLX_IMAGE_H

# include <mlx.h>

/*
** img_ptr		- return value of mlx_new_image
** img_data		- store image. Return value of mlx_get_data_addr
** size_line	- number of bytes used to store one line of the image in
** 					memory. Set in mlx_get_data_addr
** bpp			- number of bits needed to represent a pixel color. Set
** 					in mlx_get_data_addr
** endian		- endian tells you wether the pixel color in the
**     				image needs to be stored in little endian ( endian == 0),
**    				or big endian ( endian == 1). Set in mlx_get_data_addr
*/

	typedef struct		s_img
	{
		void			*img_ptr;
		unsigned int	*img_data;
		int				size_line;
		int				bpp;
		int				endian;
}					t_img;

/*
** mlx_ptr -	return value of mlx_init()
** win_ptr -	return value of mlx_new_window
** img -		store all information about image for drawing. Structure
** 					is defined above.
*/

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	t_img			img;
}					t_mlx;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			dirx;
	int			diry;
}				t_line;

typedef struct	s_gradient
{
	float		r;
	float		g;
	float		b;
	float		dr;
	float		dg;
	float		db;
}				t_gradient;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;


void				init_img_struct(t_mlx *mlx, int width, int height);
void				put_pixel_to_img(t_img *img, int x, int y, int color);
t_mlx				*init_mlx_and_img(int width, int height, char *title);
void			draw_gradient_bresenham_line(t_mlx *mlx, t_point p1,
											 t_point p2);
int				getnext_color_gradient(t_gradient *grad);
void			init_lineparams(t_line *line, t_point *p1, t_point *p2);
void			init_gradientparams(t_gradient *grad, t_point *p1,
										t_point *p2);
unsigned char	rgb_get_bvalue(int color);
int				rgb_get_color(int r, int g, int b);
unsigned char	rgb_get_gvalue(int color);
unsigned char	rgb_get_rvalue(int color);
#endif
