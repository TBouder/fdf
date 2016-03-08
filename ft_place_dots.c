/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_dots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:33:42 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/08 19:57:53 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_place_dots() functions place the dots on the map, with links between
** same z.
** The number indicates the degree of rotation :
** 1 = 0º && 2 = 90º && 3 = 180º && 4 = 270º
*/

void		ft_place_dots_1(t_win w, t_dot *dot)
{
	float		x;
	float		y;
	int			i;

	while (dot)
	{
		i = -1;
		x = (dot->x + dot->y) * w.zoom;
		y = (dot->y - dot->x) * w.zoom - (dot->z * w.zoom * 2.7 * w.zoom_z);
		while (i++ < w.zoom)
		{
			if (ft_dotnext(dot, w.x) && ft_dotnext(dot, w.x)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x) + (x + i),
					(w.obj_y) + (y + i) * ft_sin(30), 16777215);
			if (dot->next && dot->x % w.x != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x) + (x + i),
					(w.obj_y) + (y - i) * ft_sin(30), 16777215);
		}
		dot->x = lroundf((w.obj_x) + (x));
		dot->y = lroundf((w.obj_y) + (y) * ft_sin(30));
		dot = dot->next;
	}
}

void		ft_place_dots_2(t_win w, t_dot *dot)
{
	float		x;
	float		y;
	int			i;

	while (dot)
	{
		i = -1;
		x = -((dot->x - dot->y) * w.zoom + (dot->z * w.zoom * 2.7 * w.zoom_z));
		y = (-dot->y - dot->x) * w.zoom;
		while (i++ < w.zoom)
		{
			if (dot->next && dot->x % w.x != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x + w.max_x / 4) + (x - i) * ft_sin(30),
					(w.obj_y + w.max_y / 4) + (y - i), 16777215);
			if (ft_dotnext(dot, w.x) && ft_dotnext(dot, w.x)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x + w.max_x / 4) + (x + i) * ft_sin(30),
					(w.obj_y + w.max_y / 4) + (y - i), 16777215);
		}
		dot->x = lroundf((w.obj_x + w.max_x / 4) + (x) * ft_sin(30));
		dot->y = lroundf((w.obj_y + w.max_y / 4) + (y));
		dot = dot->next;
	}
}

void		ft_place_dots_3(t_win w, t_dot *dot)
{
	float		x;
	float		y;
	int			i;

	while (dot)
	{
		i = -1;
		x = -((dot->x + dot->y) * w.zoom);
		y = -((dot->y - dot->x) * w.zoom + (dot->z * w.zoom * 2.7 * w.zoom_z));
		while (i++ < w.zoom)
		{
			if (ft_dotnext(dot, w.x) && ft_dotnext(dot, w.x)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x + w.max_x / 2) + (x - i),
					(w.obj_y) + (y - i) * ft_sin(30), 16777215);
			if (dot->next && dot->x % w.x != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x + w.max_x / 2) + (x - i),
					(w.obj_y) + (y + i) * ft_sin(30), 16777215);
		}
		dot->x = lroundf((w.obj_x + w.max_x / 2) + (x));
		dot->y = lroundf((w.obj_y) + (y) * ft_sin(30));
		dot = dot->next;
	}
}

void		ft_place_dots_4(t_win w, t_dot *dot)
{
	float		x;
	float		y;
	int			i;

	while (dot)
	{
		i = -1;
		x = -((dot->x - dot->y) * w.zoom + (dot->z * w.zoom * 2.7 * w.zoom_z));
		y = (dot->y + dot->x) * w.zoom;
		while (i++ < w.zoom)
		{
			if (dot->next && dot->x % w.x != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x + w.max_x / 4) + (x - i) * ft_sin(-30),
					(w.obj_y / 2) + (y + i), 16777215);
			if (ft_dotnext(dot, w.x) && ft_dotnext(dot, w.x)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x + w.max_x / 4) + (x + i) * ft_sin(-30),
					(w.obj_y / 2) + (y + i), 16777215);
		}
		dot->x = lroundf((w.obj_x + w.max_x / 4) + (x) * ft_sin(-30));
		dot->y = lroundf((w.obj_y / 2) + (y));
		dot = dot->next;
	}
}
