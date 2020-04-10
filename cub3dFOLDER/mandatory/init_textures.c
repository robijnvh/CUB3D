/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 10:57:57 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/09 14:05:10 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_sprite(t_vars *win)
{
	win->t.mlx_sp = mlx_init();
	if (check_file_type(win->data->s))
	{
		if (mlx_png_file_to_image(win->t.mlx_sp, win->data->s,
		&win->t.img_wid_sp, &win->t.img_height_sp))
			win->t.img_sp = mlx_png_file_to_image(win->t.mlx_sp, win->data->s,
			&win->t.img_wid_sp, &win->t.img_height_sp);
		else
			return (return_error("WRONG PATH SPRITE\n", 0));
	}
	else
	{
		if (mlx_xpm_file_to_image(win->t.mlx_sp, win->data->s,
		&win->t.img_wid_sp, &win->t.img_height_sp))
			win->t.img_sp = mlx_xpm_file_to_image(win->t.mlx_sp, win->data->s,
			&win->t.img_wid_sp, &win->t.img_height_sp);
		else
			return (return_error("WRONG PATH SPRITE\n", 0));
	}
	win->t.addr_sp = mlx_get_data_addr(win->t.img_sp, &win->t.bpp_sp,
	&win->t.line_length_sp, &win->t.endian_sp);
	return (1);
}

int		set_textures4(t_vars *win)
{
	win->t.mlx_ea = mlx_init();
	if (check_file_type(win->data->ea))
	{
		if (mlx_png_file_to_image(win->t.mlx_ea, win->data->ea,
		&win->t.img_width_ea, &win->t.img_height_ea))
			win->t.img_ea = mlx_png_file_to_image(win->t.mlx_ea, win->data->ea,
			&win->t.img_width_ea, &win->t.img_height_ea);
		else
			return (return_error("WRONG PATH EAST\n", 0));
	}
	else
	{
		if (mlx_xpm_file_to_image(win->t.mlx_ea, win->data->ea,
		&win->t.img_width_ea, &win->t.img_height_ea))
			win->t.img_ea = mlx_xpm_file_to_image(win->t.mlx_ea, win->data->ea,
			&win->t.img_width_ea, &win->t.img_height_ea);
		else
			return (return_error("WRONG PATH EAST\n", 0));
	}
	win->t.addr_ea = mlx_get_data_addr(win->t.img_ea, &win->t.bits_per_pixel_ea,
	&win->t.line_length_ea, &win->t.endian_ea);
	return (1);
}

int		set_textures3(t_vars *win)
{
	win->t.mlx_we = mlx_init();
	if (check_file_type(win->data->we))
	{
		if (mlx_png_file_to_image(win->t.mlx_we, win->data->we,
		&win->t.img_width_we, &win->t.img_height_we))
			win->t.img_we = mlx_png_file_to_image(win->t.mlx_we, win->data->we,
			&win->t.img_width_we, &win->t.img_height_we);
		else
			return (return_error("WRONG PATH WEST\n", 0));
	}
	else
	{
		if (mlx_xpm_file_to_image(win->t.mlx_we, win->data->we,
		&win->t.img_width_we, &win->t.img_height_we))
			win->t.img_we = mlx_xpm_file_to_image(win->t.mlx_we, win->data->we,
			&win->t.img_width_we, &win->t.img_height_we);
		else
			return (return_error("WRONG PATH WEST\n", 0));
	}
	win->t.addr_we = mlx_get_data_addr(win->t.img_we, &win->t.bits_per_pixel_we,
	&win->t.line_length_we, &win->t.endian_we);
	return (set_textures4(win));
}

int		set_textures2(t_vars *win)
{
	win->t.mlx_so = mlx_init();
	if (check_file_type(win->data->so))
	{
		if (mlx_png_file_to_image(win->t.mlx_so, win->data->so,
		&win->t.img_width_so, &win->t.img_height_so))
			win->t.img_so = mlx_png_file_to_image(win->t.mlx_so, win->data->so,
			&win->t.img_width_so, &win->t.img_height_so);
		else
			return (return_error("WRONG PATH SOUTH\n", 0));
	}
	else
	{
		if (mlx_xpm_file_to_image(win->t.mlx_so, win->data->so,
		&win->t.img_width_so, &win->t.img_height_so))
			win->t.img_so = mlx_xpm_file_to_image(win->t.mlx_so, win->data->so,
			&win->t.img_width_so, &win->t.img_height_so);
		else
			return (return_error("WRONG PATH SOUTH\n", 0));
	}
	win->t.addr_so = mlx_get_data_addr(win->t.img_so, &win->t.bits_per_pixel_so,
	&win->t.line_length_so, &win->t.endian_so);
	return (set_textures3(win));
}

int		set_textures(t_vars *win)
{
	win->t.mlx_no = mlx_init();
	if (check_file_type(win->data->no))
	{
		if (mlx_png_file_to_image(win->t.mlx_no, win->data->no,
		&win->t.img_width_no, &win->t.img_height_no))
			win->t.img_no = mlx_png_file_to_image(win->t.mlx_no, win->data->no,
			&win->t.img_width_no, &win->t.img_height_no);
		else
			return (return_error("WRONG PATH NORTH\n", 0));
	}
	else
	{
		if (mlx_xpm_file_to_image(win->t.mlx_no, win->data->no,
		&win->t.img_width_no, &win->t.img_height_no))
			win->t.img_no = mlx_xpm_file_to_image(win->t.mlx_no, win->data->no,
			&win->t.img_width_no, &win->t.img_height_no);
		else
			return (return_error("WRONG PATH NORTH\n", 0));
	}
	win->t.addr_no = mlx_get_data_addr(win->t.img_no, &win->t.bits_per_pixel_no,
	&win->t.line_length_no, &win->t.endian_no);
	return (set_textures2(win));
}
