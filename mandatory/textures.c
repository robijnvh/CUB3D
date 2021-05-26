/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:44:17 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/09 14:06:37 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tex_no2(t_vars *win, double x1, double size_search, int i)
{
	char	*dst_tex;

	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_no + ((win->t.tex_mid_no -
		(int)(win->t.i_tex_no - ((double)win->t.tex_mid_no / size_search))) *
		win->t.line_length_no + win->t.x_no * (win->t.bits_per_pixel_no / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void	print_tex_no(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;

	i = 0;
	win->t.i_tex_no = 0.0;
	win->t.tex_mid_no = win->t.img_height_no / 2;
	win->t.x_no = win->data->tex_size * win->t.img_width_no;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < (int)size)
	{
		dst_tex = win->t.addr_no + ((win->t.tex_mid_no + (int)win->t.i_tex_no) *
		win->t.line_length_no + win->t.x_no * (win->t.bits_per_pixel_no / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_no + ((win->t.tex_mid_no - (int)win->t.i_tex_no) *
		win->t.line_length_no + win->t.x_no * (win->t.bits_per_pixel_no / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		win->t.i_tex_no += ((double)win->t.tex_mid_no / size_search);
		i++;
	}
	print_tex_no2(win, x1, size_search, i);
}

void	print_tex_so2(t_vars *win, double x1, double size_search, int i)
{
	char *dst_tex;

	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_so + ((win->t.tex_mid_so -
		(int)(win->t.i_tex_so - ((double)win->t.tex_mid_so / size_search))) *
		win->t.line_length_so + win->t.x_so * (win->t.bits_per_pixel_so / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void	print_tex_so(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;

	i = 0;
	win->t.i_tex_so = 0.0;
	win->t.tex_mid_so = win->t.img_height_so / 2;
	win->t.x_so = win->data->tex_size * win->t.img_width_so;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < size)
	{
		dst_tex = win->t.addr_so + ((win->t.tex_mid_so + (int)win->t.i_tex_so) *
		win->t.line_length_so + win->t.x_so * (win->t.bits_per_pixel_so / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_so + ((win->t.tex_mid_so - (int)win->t.i_tex_so) *
		win->t.line_length_so + win->t.x_so * (win->t.bits_per_pixel_so / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		win->t.i_tex_so += ((double)win->t.tex_mid_so / size_search);
		i++;
	}
	print_tex_so2(win, x1, size_search, i);
}

void	put_texture(t_vars *win, double x1, int size, double size_search)
{
	if (win->data->side == 1)
	{
		win->data->tex_hit = win->data->ray_length * cos(win->angle);
		win->data->tex_y = win->data->start_y + win->data->tex_hit;
		win->data->tex_size = win->data->tex_y - (int)win->data->tex_y;
		if (win->angle >= 0 * M_PI && win->angle <= 1 * M_PI)
			print_tex_ea(win, x1, size, size_search);
		else
			print_tex_we(win, x1, size, size_search);
	}
	else if (win->data->side == 0)
	{
		win->data->tex_hit = win->data->ray_length * sin(win->angle);
		win->data->tex_x = win->data->start_x + win->data->tex_hit;
		win->data->tex_size = win->data->tex_x - (int)win->data->tex_x;
		if (win->angle >= 0.5 * M_PI && win->angle <= 1.5 * M_PI)
			print_tex_no(win, x1, size, size_search);
		else
			print_tex_so(win, x1, size, size_search);
	}
}
