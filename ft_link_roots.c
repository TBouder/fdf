/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_roots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:44:10 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 18:44:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

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

void			ft_create_fdf_helper(t_win w)
{
	ft_place_dots_4(w, w.dot);
	ft_link_one_4(w, w.dot);
	ft_link_two_4(w, w.dot);
}

void			ft_create_fdf(t_win w, int i)
{
	i == 1 ? ft_restore_origin(w.dot, w) : 0;
	ft_print_infos(w);
	if (w.rotation == 1)
	{
		ft_place_dots_1(w, w.dot);
		// ft_link_one_1(w, w.dot);
		ft_link_two_1(w, w.dot);
	}
	else if (w.rotation == 2)
	{
		ft_place_dots_2(w, w.dot);
		ft_link_one_2(w, w.dot);
		ft_link_two_2(w, w.dot);
	}
	else if (w.rotation == 3)
	{
		ft_place_dots_3(w, w.dot);
		ft_link_one_3(w, w.dot);
		ft_link_two_3(w, w.dot);
	}
	else if (w.rotation == 4)
		ft_create_fdf_helper(w);
}
