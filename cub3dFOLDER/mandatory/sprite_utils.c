/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 11:48:27 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/09 14:04:39 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		make_sprite2(t_vars *win, int i, int x)
{
	char	*dst;

	if (win->data->rh % 2 == 0 && win->num == 0)
	{
		dst = win->t.addr_sp + ((int)((win->t.h_win * (i - 1)) + win->t.h_sp)
		* win->t.line_length_sp + win->t.x1);
		if (*(unsigned int*)dst != 0x00000000)
			my_mlx_pixel_put2(win, x, win->window_mid + i, *(unsigned int*)dst);
		dst = win->t.addr_sp + ((int)(win->t.h_sp - (win->t.h_win * i))
		* win->t.line_length_sp + win->t.x1);
		if (*(unsigned int*)dst != 0x00000000)
			my_mlx_pixel_put2(win, x, win->window_mid - i, *(unsigned int*)dst);
	}
	if (win->data->rh % 2 == 0)
	{
		dst = win->t.addr_sp + ((int)(win->t.h_sp - (win->t.h_win * i))
		* win->t.line_length_sp + win->t.x1);
		if (*(unsigned int*)dst != 0x00000000)
			my_mlx_pixel_put2(win, x, win->window_mid - i, *(unsigned int*)dst);
	}
}

void		make_sprite(t_vars *win, float distance, float on_wall, int x)
{
	int		i;
	char	*dst;

	i = 0;
	win->t.x1 = (int)(win->t.img_wid_sp * on_wall) * (win->t.bpp_sp / 8);
	win->t.h_win = ((win->t.img_height_sp) / (distance * win->data->rh));
	if (!(distance < 1))
		distance = 0.999999;
	win->data->end = (distance * (float)win->data->rh) / 2;
	win->t.h_sp = (win->t.img_height_sp / 2);
	if (win->num == 0 && win->data->rh % 2 == 0)
		win->data->end -= 1;
	while (i <= win->data->end)
	{
		dst = win->t.addr_sp + ((int)((win->t.h_win * i) + win->t.h_sp)
		* win->t.line_length_sp + win->t.x1);
		if (*(unsigned int*)dst != 0x00000000)
			my_mlx_pixel_put2(win, x, win->window_mid + i, *(unsigned int*)dst);
		dst = win->t.addr_sp + ((int)(win->t.h_sp - (win->t.h_win * i))
		* win->t.line_length_sp + win->t.x1);
		if (*(unsigned int*)dst != 0x00000000)
			my_mlx_pixel_put2(win, x, win->window_mid - i, *(unsigned int*)dst);
		i++;
	}
	make_sprite2(win, i, x);
}

void		find_intersect_y(t_vars *win, int sign, int sign2, float step)
{
	float ray;
	float raystep;
	float y;
	float sp_step;
	float amount;

	win->data->on_wall_sprite[win->data->i] = -1;
	y = 0.5 + ((0.5 * fabs(tan(win->data->sp_angle_l))) * sign);
	raystep = step * tan(win->angle) * -1;
	sp_step = step * tan(win->data->sp_angle_l) * -1;
	amount = (win->on_wall - y) / (sp_step - raystep);
	ray = win->on_wall + (raystep * amount);
	if (ray > 0.0 && ray < 0.5)
		win->data->on_wall_sprite[win->data->i] = 0.5 + ((fabs(ray - 0.5)) /
		(sin(win->data->sp_angle_l)) * sign2);
	else if (ray >= 0.5 && ray < 1.0)
		win->data->on_wall_sprite[win->data->i] = (ray - 0.5) /
		fabs(sin(win->data->sp_angle_r)) + 0.5;
	if (!(win->data->on_wall_sprite[win->data->i] > 0.0 &&
	win->data->on_wall_sprite[win->data->i] < 1.0))
		win->data->on_wall_sprite[win->data->i] = -1;
}

void		find_intersect_x2(t_vars *win, float ray, int sign2)
{
	if (ray > 0.0 && ray < 0.5)
		win->data->on_wall_sprite[win->data->i] = 0.5 - (fabs(ray - 0.5)) /
		(cos(win->data->sp_angle_l));
	else if (ray >= 0.5 && ray < 1.0 && sign2 == 0)
		win->data->on_wall_sprite[win->data->i] = ((ray - 0.5) /
		fabs(cos(win->data->sp_angle_r)) + 0.5);
	else if (ray >= 0.5 && ray < 1.0 && sign2 == 1)
		win->data->on_wall_sprite[win->data->i] = 1.0 - ((ray - 0.5) /
		fabs(cos(win->data->sp_angle_r)) + 0.5);
	if (!(win->data->on_wall_sprite[win->data->i] > 0.0 &&
	win->data->on_wall_sprite[win->data->i] < 1.0))
		win->data->on_wall_sprite[win->data->i] = -1;
}

void		find_intersect_x(t_vars *win, float sign, int sign2, float step)
{
	float ray;
	float raystep;
	float y;
	float sp_step;
	float amount;

	win->data->on_wall_sprite[win->data->i] = -1;
	if (sign == -0.5 && (win->angle > 1.5 * M_PI && win->angle <= 2 * M_PI))
		y = 0.5 + sign / fabs(tan(win->data->sp_angle_r));
	else
		y = 0.5 + sign / fabs(tan(win->data->sp_angle_l));
	raystep = step / tan(win->angle);
	if (sign == 0.5)
		sp_step = step / tan(win->data->sp_angle_l);
	else
		sp_step = step / tan(win->data->sp_angle_r);
	amount = (win->on_wall - y) / (sp_step - raystep);
	ray = win->on_wall + (raystep * amount);
	find_intersect_x2(win, ray, sign2);
}
