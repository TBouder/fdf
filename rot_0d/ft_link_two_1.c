/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_two_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:23:22 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 18:47:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static void		ft_link_down_to_up_v(t_win w, t_dot *dot, t_dot *dot_next)
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)w.zoom / (-(dot_next->y - dot->y));
	x = dot->x;
	y = dot->y;
	while (coef_y > 0 && y > dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot_next->color);
		x += coef_y;
		y -= 1;
	}
	while (coef_y < 0 && y < dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot_next->color);
		x -= coef_y;
		y += 1;
	}
}

static void		ft_link_up_to_down_v(t_win w, t_dot *dot, t_dot *dot_next)
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)w.zoom / (dot_next->y - dot->y);
	x = dot->x;
	y = dot->y;
	while (coef_y > 0 && y < dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		x += coef_y;
		y += 1;
	}
	while (coef_y < 0 && y > dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		x -= coef_y;
		y -= 1;
	}
}

void			ft_link_two_1(t_win w, t_dot *dot)
{
	t_dot	*dot_next;

	dot_next = ft_dotnext(dot, w.x);
	while (dot_next)
	{
		if (dot_next->z > dot->z)
			ft_link_down_to_up_v(w, dot, dot_next);
		if (dot_next->z < dot->z)
			ft_link_up_to_down_v(w, dot, dot_next);
		dot = dot->next;
		dot_next = ft_dotnext(dot, w.x);
	}
}
