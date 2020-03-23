/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 17:44:17 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/23 16:11:11 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			print_tex_no(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;
	int		x;
	int		tex_mid;
	double	i_tex;

	i = 0;
	i_tex = 0.0;
	tex_mid = win->t.img_height_no / 2;
	x = win->data->tex_size * win->t.img_width_no;
	// printf("-------------------------\n");
	if (win->data->rh % 2 != 0)
	{
		// printf("check 1\n");		
		size++;
	}
	// printf("i 1: %i\n", i);	
	// printf("size i: %d\n", (int)size);
	// printf("size f: %f\n", size);
	while (i < (int)size)
	{
		// printf("check 2\n");
		dst_tex = win->t.addr_no + ((tex_mid + (int)i_tex) *
		win->t.line_length_no + x * (win->t.bits_per_pixel_no / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_no + ((tex_mid - (int)i_tex) *
		win->t.line_length_no + x * (win->t.bits_per_pixel_no / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i_tex += ((double)tex_mid / size_search);
		i++;
	}
	// printf("i 2: %i\n", i);
	if (win->data->rh % 2 == 0)
	{
		// printf("check 3\n");
		dst_tex = win->t.addr_no + ((tex_mid - (int)(i_tex - ((double)tex_mid / size_search))) *
		win->t.line_length_no + x * (win->t.bits_per_pixel_no / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	// printf("i 3: %i\n", i);
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void			print_tex_so(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;
	int		x;
	int		tex_mid;
	double	i_tex;

	i = 0;
	i_tex = 0.0;
	tex_mid = win->t.img_height_so / 2;
	x = win->data->tex_size * win->t.img_width_so;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < size)
	{
		dst_tex = win->t.addr_so + ((tex_mid + (int)i_tex) *
		win->t.line_length_so + x * (win->t.bits_per_pixel_so / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_so + ((tex_mid - (int)i_tex) *
		win->t.line_length_so + x * (win->t.bits_per_pixel_so / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i_tex += ((double)tex_mid / size_search);
		i++;
	}
	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_so + ((tex_mid - (int)(i_tex - ((double)tex_mid / size_search))) *
		win->t.line_length_so + x * (win->t.bits_per_pixel_so / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void			print_tex_we(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;
	int		x;
	int		tex_mid;
	double	i_tex;

	i = 0;
	i_tex = 0.0;
	tex_mid = win->t.img_height_we / 2;
	x = win->data->tex_size * win->t.img_width_we;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < size)
	{
		dst_tex = win->t.addr_we + ((tex_mid + (int)i_tex) *
		win->t.line_length_we + x * (win->t.bits_per_pixel_we / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_we + ((tex_mid - (int)i_tex) *
		win->t.line_length_we + x * (win->t.bits_per_pixel_we / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i_tex += ((double)tex_mid / size_search);
		i++;
	}
	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_we + ((tex_mid - (int)(i_tex - ((double)tex_mid / size_search))) *
		win->t.line_length_we + x * (win->t.bits_per_pixel_we / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void			print_tex_ea(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;
	int		x;
	int		tex_mid;
	double	i_tex;

	i = 0;
	i_tex = 0.0;
	tex_mid = win->t.img_height_ea / 2;
	x = win->data->tex_size * win->t.img_width_ea;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < size)
	{
		dst_tex = win->t.addr_ea + ((tex_mid + (int)i_tex) *
		win->t.line_length_ea + x * (win->t.bits_per_pixel_ea / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_ea + ((tex_mid - (int)i_tex) *
		win->t.line_length_ea + x * (win->t.bits_per_pixel_ea / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i_tex += ((double)tex_mid / size_search);
		i++;
	}
	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_ea + ((tex_mid - (int)(i_tex - ((double)tex_mid / size_search))) *
		win->t.line_length_ea + x * (win->t.bits_per_pixel_ea / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void			put_texture(t_vars *win, double x1, int size, double size_search)
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
