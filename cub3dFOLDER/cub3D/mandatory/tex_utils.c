/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 12:00:49 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/12 19:16:11 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor(t_vars *win, int i, double x1)
{
	i += win->window_mid;
	while (i < win->data->rh)
	{
		my_mlx_pixel_put2(win, x1, i, win->data->floor);
		i++;
	}
}

void	set_ceiling(t_vars *win, int i, double x1)
{
	while ((win->window_mid - i) >= 0)
	{
		my_mlx_pixel_put2(win, x1, win->window_mid - i, win->data->ceiling);
		i++;
	}
}

int		set_sprite(t_vars *win)
{
	win->t.mlx_sp = mlx_init();
	// if (check_file_type(win->data->s))
	// 	win->t.img_sp = mlx_png_file_to_image(win->t.mlx_sp, win->data->s,
	// 	&win->t.img_width_sp, &win->t.img_height_sp);
	// else
		win->t.img_sp = mlx_xpm_file_to_image(win->t.mlx_sp, win->data->s,
		&win->t.img_width_sp, &win->t.img_height_sp);
	if (win->t.img_height_sp <= 0 || win->t.img_width_sp <= 0)
		return (return_error("WRONG PATH SPRITE\n", 0));
	win->t.addr_sp = mlx_get_data_addr(win->t.img_sp, &win->t.bits_per_pixel_sp,
	&win->t.line_length_sp, &win->t.endian_sp);
	return (1);
}

int		set_textures2(t_vars *win)
{
	win->t.mlx_we = mlx_init();
	// if (check_file_type(win->data->we))
	// 	win->t.img_we = mlx_png_file_to_image(win->t.mlx_we, win->data->we,
	// 	&win->t.img_width_we, &win->t.img_height_we);
	// else
		win->t.img_we = mlx_xpm_file_to_image(win->t.mlx_we, win->data->we,
		&win->t.img_width_we, &win->t.img_height_we);
	if (win->t.img_height_we <= 0 || win->t.img_width_we <= 0)
		return (return_error("WRONG PATH WEST\n", 0));
	win->t.addr_we = mlx_get_data_addr(win->t.img_we, &win->t.bits_per_pixel_we,
	&win->t.line_length_we, &win->t.endian_we);
	win->t.mlx_ea = mlx_init();
	// if (check_file_type(win->data->ea))
	// 	win->t.img_ea = mlx_png_file_to_image(win->t.mlx_ea, win->data->ea,
	// 	&win->t.img_width_ea, &win->t.img_height_ea);
	// else
		win->t.img_ea = mlx_xpm_file_to_image(win->t.mlx_ea, win->data->ea,
		&win->t.img_width_ea, &win->t.img_height_ea);
	if (win->t.img_height_ea <= 0 || win->t.img_width_ea <= 0)
		return (return_error("WRONG PATH EAST\n", 0));
	win->t.addr_ea = mlx_get_data_addr(win->t.img_ea, &win->t.bits_per_pixel_ea,
	&win->t.line_length_ea, &win->t.endian_ea);
	return (1);
}

int		set_textures(t_vars *win)
{
	// return (0);
	// win->data->sprite = 0;
	win->t.mlx_no = mlx_init();
	// if (check_file_type(win->data->no))
	// 	win->t.img_no = mlx_png_file_to_image(win->t.mlx_no, win->data->no,
	// 	&win->t.img_width_no, &win->t.img_height_no);
	// else
		win->t.img_no = mlx_xpm_file_to_image(win->t.mlx_no, win->data->no,
		&win->t.img_width_no, &win->t.img_height_no);
	if (win->t.img_height_no <= 0 || win->t.img_width_no <= 0)
		return (return_error("WRONG PATH NORTH\n", 0));
	win->t.addr_no = mlx_get_data_addr(win->t.img_no, &win->t.bits_per_pixel_no,
	&win->t.line_length_no, &win->t.endian_no);
	win->t.mlx_so = mlx_init();
	// if (check_file_type(win->data->so))
	// 	win->t.img_so = mlx_png_file_to_image(win->t.mlx_so, win->data->so,
	// 	&win->t.img_width_so, &win->t.img_height_so);
	// else
		win->t.img_so = mlx_xpm_file_to_image(win->t.mlx_so, win->data->so,
		&win->t.img_width_so, &win->t.img_height_so);
	if (win->t.img_height_so <= 0 || win->t.img_width_so <= 0)
		return (return_error("WRONG PATH SOUTH\n", 0));
	win->t.addr_so = mlx_get_data_addr(win->t.img_so, &win->t.bits_per_pixel_so,
	&win->t.line_length_so, &win->t.endian_so);
	return (set_textures2(win));
}
