/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 11:56:49 by robijnvanho   #+#    #+#                 */
/*   Updated: 2020/04/09 14:07:06 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tex_we2(t_vars *win, double x1, double size_search, int i)
{
	char	*dst_tex;

	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_we + ((win->t.tex_mid_we -
		(int)(win->t.i_tex_we - ((double)win->t.tex_mid_we / size_search))) *
		win->t.line_length_we + win->t.x_we * (win->t.bits_per_pixel_we / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void	print_tex_we(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;

	i = 0;
	win->t.i_tex_we = 0.0;
	win->t.tex_mid_we = win->t.img_height_we / 2;
	win->t.x_we = win->data->tex_size * win->t.img_width_we;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < size)
	{
		dst_tex = win->t.addr_we + ((win->t.tex_mid_we + (int)win->t.i_tex_we) *
		win->t.line_length_we + win->t.x_we * (win->t.bits_per_pixel_we / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_we + ((win->t.tex_mid_we - (int)win->t.i_tex_we) *
		win->t.line_length_we + win->t.x_we * (win->t.bits_per_pixel_we / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		win->t.i_tex_we += ((double)win->t.tex_mid_we / size_search);
		i++;
	}
	print_tex_we2(win, x1, size_search, i);
}

void	print_tex_ea2(t_vars *win, double x1, double size_search, int i)
{
	char	*dst_tex;

	if (win->data->rh % 2 == 0)
	{
		dst_tex = win->t.addr_ea + ((win->t.tex_mid_ea -
		(int)(win->t.i_tex_ea - ((double)win->t.tex_mid_ea / size_search))) *
		win->t.line_length_ea + win->t.x_ea * (win->t.bits_per_pixel_ea / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		i++;
	}
	set_floor(win, i, x1);
	set_ceiling(win, i, x1);
}

void	print_tex_ea(t_vars *win, double x1, int size, double size_search)
{
	char	*dst_tex;
	int		i;

	i = 0;
	win->t.i_tex_ea = 0.0;
	win->t.tex_mid_ea = win->t.img_height_ea / 2;
	win->t.x_ea = win->data->tex_size * win->t.img_width_ea;
	if (win->data->rh % 2 != 0)
		size++;
	while (i < size)
	{
		dst_tex = win->t.addr_ea + ((win->t.tex_mid_ea + (int)win->t.i_tex_ea) *
		win->t.line_length_ea + win->t.x_ea * (win->t.bits_per_pixel_ea / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid + i,
		*(unsigned int*)dst_tex);
		dst_tex = win->t.addr_ea + ((win->t.tex_mid_ea - (int)win->t.i_tex_ea) *
		win->t.line_length_ea + win->t.x_ea * (win->t.bits_per_pixel_ea / 8));
		my_mlx_pixel_put2(win, x1, win->window_mid - i,
		*(unsigned int*)dst_tex);
		win->t.i_tex_ea += ((double)win->t.tex_mid_ea / size_search);
		i++;
	}
	print_tex_ea2(win, x1, size_search, i);
}
