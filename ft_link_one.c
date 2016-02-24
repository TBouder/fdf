/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 20:01:41 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/24 13:26:28 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void		ft_link_down_to_up_h(t_win w, t_dot *dot, t_dot *dot_next) //GREEN
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)w.zoom / (-(dot_next->y - dot->y));
	x = dot->x;
	y = dot->y;
	while (y > dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, 65408);
		x += coef_y;
		y -= 1;
	}
}

static void		ft_link_up_to_down_h(t_win w, t_dot *dot, t_dot *dot_next) //BLUE
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)w.zoom / (dot_next->y - dot->y);
	x = dot->x;
	y = dot->y;
	while (y < dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, 3113674);
		x += coef_y;
		y += 1;
	}
}

void			ft_link_one(t_win w, t_dot *dot)
{
	t_dot	*dot_next;

	dot_next = dot->next;
	while (dot_next)
	{
		if (dot_next->z > dot->z)
			ft_link_down_to_up_h(w, dot, dot_next);
		if (dot_next->z < dot->z && dot->id % w.x_max != w.x_max - 1)
			ft_link_up_to_down_h(w, dot, dot_next);
		dot = dot->next;
		dot_next = dot->next;
	}
}
