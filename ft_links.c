/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:23:22 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/18 16:49:34 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_dot		*ft_dotnext(t_dot *dot, int n)
{
	int		i;

	i = 0;
	if (dot == NULL)
		return (0);
	while (i < n)
	{
		dot = dot->next;
		if (dot == NULL)
			return (NULL);
		i++;
	}
	return (dot);
}

void		ft_place_dots(t_win w, t_dot *dot)
{
	float		x;
	float		y;
	int			i;
	int			max_x;

	max_x = ft_max_x(dot);
	while (dot)
	{
		i = -1;
		x = (dot->x + dot->y) * ZOOM;
		y = (dot->y - dot->x) * ZOOM - (dot->z * ZOOM * 2.7);
		while (i++ < ZOOM)
		{
			if (ft_dotnext(dot, max_x) && ft_dotnext(dot, max_x)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window, (POS_X) + (x + i), (POS_Y) +
					(y + i) * sin(30 * (PI / 180)), 16777215);

			if (dot->next && dot->x % max_x != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window, (POS_X) + (x + i), (POS_Y) +
					(y - i) * sin(30 * (PI / 180)), 16777215);
		}
		dot->x = lroundf((POS_X) + (x));
		dot->y = lroundf((POS_Y) + (y) * sin(30 * (PI / 180)));
		dot = dot->next;
	}
}

/*----------*/

void		ft_link_down_to_up_h(t_win w, t_dot *dot, t_dot *dot_next) //GREEN
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)ZOOM / (-(dot_next->y - dot->y));
	x = dot->x;
	y = dot->y;
	while (y > dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, 65408);
		x += coef_y;
		y -= 1;
	}
}

void		ft_link_up_to_down_h(t_win w, t_dot *dot, t_dot *dot_next) //BLUE
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)ZOOM / (dot_next->y - dot->y);
	x = dot->x;
	y = dot->y;
	while (y < dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, 3113674);
		x += coef_y;
		y += 1;
	}
}

void		ft_link_down_to_up_v(t_win w, t_dot *dot, t_dot *dot_next)
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)ZOOM / (-(dot_next->y - dot->y));
	x = dot->x;
	y = dot->y;
	while (y > dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, 16669806);
		x += coef_y;
		y -= 1;
	}
}

void		ft_link_up_to_down_v(t_win w, t_dot *dot, t_dot *dot_next)
{
	float		x;
	float		y;
	float		coef_y;

	coef_y = (float)ZOOM / (dot_next->y - dot->y);
	x = dot->x;
	y = dot->y;
	while (y < dot_next->y)
	{
		mlx_pixel_put(w.mlx, w.window, x, y, 16610324);
		x += coef_y;
		y += 1;
	}
}

/*----------*/

void		ft_link_one(t_win w, t_dot *dot, int max_x)
{
	t_dot	*dot_next;

	dot_next = dot->next;
	while (dot_next)
	{
		if (dot_next->z > dot->z)
			ft_link_down_to_up_h(w, dot, dot_next);
		if (dot_next->z < dot->z && dot->id % max_x != max_x - 1)
			ft_link_up_to_down_h(w, dot, dot_next);
		dot = dot->next;
		dot_next = dot->next;
	}
}

void		ft_link_two(t_win w, t_dot *dot, int max_x)
{
	t_dot	*dot_next;

	dot_next = ft_dotnext(dot, max_x);
	while (dot_next)
	{
		if (dot_next->z > dot->z)
			ft_link_down_to_up_v(w, dot, dot_next);
		if (dot_next->z < dot->z)
			ft_link_up_to_down_v(w, dot, dot_next);
		dot = dot->next;
		dot_next = ft_dotnext(dot, max_x);
	}
}

