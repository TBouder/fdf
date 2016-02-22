/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_roots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:44:10 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/22 18:47:05 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_place_dots() function places the dots on the map, with links between
** same z. 
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
		y = (dot->y - dot->x) * w.zoom - (dot->z * w.zoom * 2.7);
		while (i++ < w.zoom)
		{
			if (ft_dotnext(dot, w.x_max) && ft_dotnext(dot, w.x_max)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window, (POS_X) + (x + i), (POS_Y) +
					(y + i) * sin(30 * (PI / 180)), 16777215);

			if (dot->next && dot->x % w.x_max != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window, (POS_X) + (x + i), (POS_Y) +
					(y - i) * sin(30 * (PI / 180)), 16777215);
		}
		dot->x = lroundf((POS_X) + (x));
		dot->y = lroundf((POS_Y) + (y) * ft_sin(30));
		dot = dot->next;
	}
}

/*
** The ft_create_fdf() function is a launcher for all the fdf creations
** fonctions.
*/

void			ft_create_fdf(t_win w, int i)
{
	if (i == 1)
		ft_restore_origin(w.dot);
	ft_place_dots(w, w.dot);
	ft_link_one(w, w.dot);
	ft_link_two(w, w.dot);
}