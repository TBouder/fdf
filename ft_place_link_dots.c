/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_link_dots.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:18:38 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/16 17:59:36 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int			ft_dotlen(t_dot *begin_dot)
{
	int		nb;

	nb = 0;
	while (begin_dot)
	{
		nb++;
		begin_dot = begin_dot->next;
	}
	return (nb);
}

t_dot		*ft_doot_z(t_dot *doot, int n)
{
	int		i;

	i = 0;
	if (doot == NULL)
		return (0);
	while (i < n)
	{
		doot = doot->next;
		if (doot == NULL)
			return (NULL);
		i++;
	}
	return (doot);
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
			if (ft_doot_z(dot, max_x) && ft_doot_z(dot, max_x)->z == dot->z)
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

void		ft_link_down_to_up(t_win w, t_dot *dot)
{
	float		a;
	int			i;

	while (dot->next)
	{
		a = (dot->next->y - dot->y) / (dot->next->x - dot->x);
		if (dot->next->z > dot->z)
		{
			i = 0;
			while (i < ZOOM * 1.9)
			{
				mlx_pixel_put(w.mlx, w.window,
					dot->x + i * (a * -tan(30 * (PI / 180))),
					dot->y - i,
					65408);
				i++;
			}
		}
		dot = dot->next;
	}
}

void		ft_place_height_second(t_win w, t_dot *dot)
{
	float		a;
	int			i;

	while (dot->next)
	{
		a = (dot->next->x - dot->x) / (dot->next->y - dot->y);
		if (dot->next->z < dot->z)
		{
			i = 0;
			while (i <= ZOOM)
			{
				mlx_pixel_put(w.mlx, w.window,
					dot->x + i,
					dot->y + i * 0.785,
					65408);
				i++;
			}
		}
		dot = dot->next;
	}
}
