/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_one_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 20:01:41 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 15:23:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static void		ft_link_down_to_up_h(t_win w, t_dot *dot, t_dot *dot_next)
{
	float		x;
	float		y;
	float		coef_x;

	coef_x = (float)w.zoom / (dot_next->x - dot->x);
	x = dot->x;
	y = dot->y;
	while (x < dot_next->x && dot->o_y == dot_next->o_y && coef_x > 0)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		y -= coef_x;
		x += 1;
	}
	while (x > dot_next->x && dot->o_y == dot_next->o_y && coef_x < 0)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		y += coef_x;
		x -= 1;
	}
}

static void		ft_link_up_to_down_h(t_win w, t_dot *dot, t_dot *dot_next)
{
	float		x;
	float		y;
	float		coef_x;

	coef_x = (float)w.zoom / (dot_next->x - dot->x);
	x = dot->x;
	y = dot->y;
	while (x < dot_next->x && coef_x > 0)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		y -= coef_x;
		x += 1;
	}
	while (x > dot_next->x && coef_x < 0)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		y += coef_x;
		x -= 1;
	}
}

void			ft_link_one_2(t_win w, t_dot *dot)
{
	t_dot	*dot_next;

	dot_next = dot->next;
	while (dot_next)
	{
		if (dot_next->z > dot->z)
			ft_link_down_to_up_h(w, dot, dot_next);
		if (dot_next->z < dot->z && dot->id % w.x != w.x - 1)
			ft_link_up_to_down_h(w, dot, dot_next);
		dot = dot->next;
		dot_next = dot->next;
	}
}
