/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_roots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:44:10 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/08 16:55:52 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_place_dots() function places the dots on the map, with links between
** same z.
** ft_sin(X) if for the orientation from down to top.
*/

static void		ft_place_dots(t_win w, t_dot *dot)
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
					(w.obj_y) + (y + i) * ft_sin(30),16777215);
			if (dot->next && dot->x % w.x != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window,
					(w.obj_x) + (x + i),
					(w.obj_y) + (y - i) * ft_sin(30),16777215);
		}
		dot->x = lroundf((w.obj_x) + (x));
		dot->y = lroundf((w.obj_y) + (y) * ft_sin(30));
		dot = dot->next;
	}
}

static void		ft_place_dots_3(t_win w, t_dot *dot)
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

/*
** Display some info on screen
*/

void			ft_print_infos(t_win w)
{
	mlx_string_put(w.mlx, w.window, 10, 10, 0xFFFFFF, "Window size : ");
	mlx_string_put(w.mlx, w.window, 150, 10, 0xFFFFFF, ft_itoa(w.max_x));
	mlx_string_put(w.mlx, w.window, 200, 10, 0xFFFFFF, "X");
	mlx_string_put(w.mlx, w.window, 220, 10, 0xFFFFFF, ft_itoa(w.max_y));
	mlx_string_put(w.mlx, w.window, 10, 30, 0xFFFFFF, "Object pos  : ");
	mlx_string_put(w.mlx, w.window, 150, 30, 0xFFFFFF, ft_itoa(w.obj_x));
	mlx_string_put(w.mlx, w.window, 200, 30, 0xFFFFFF, "X");
	mlx_string_put(w.mlx, w.window, 220, 30, 0xFFFFFF, ft_itoa(w.obj_y));
	mlx_string_put(w.mlx, w.window, 10, 50, 0xFFFFFF, "Zoom        : ");
	mlx_string_put(w.mlx, w.window, 150, 50, 0xFFFFFF, ft_itoa(w.zoom));
	mlx_string_put(w.mlx, w.window, 10, 70, 0xFFFFFF, "Z Factor    : ");
	mlx_string_put(w.mlx, w.window, 150, 70, 0xFFFFFF, ft_itoa(w.zoom_z));
}

/*
** The ft_create_fdf() function is a launcher for all the fdf creations
** fonctions.
*/

void			ft_create_fdf(t_win w, int i)
{
	if (i == 1)
		ft_restore_origin(w.dot);
	ft_print_infos(w);
	if (w.rotation == 1)
	{
		ft_place_dots(w, w.dot);
		ft_link_one(w, w.dot);
		ft_link_two(w, w.dot);
	}
	else if (w.rotation == 3)
	{
		ft_place_dots_3(w, w.dot);
		ft_link_one_3(w, w.dot);
		ft_link_two_3(w, w.dot);
	}
}
