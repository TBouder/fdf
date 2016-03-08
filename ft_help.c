/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 22:27:08 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/08 22:28:34 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void		ft_help_one(t_win *w)
{
	mlx_clear_window(w->mlx, w->window);
	mlx_string_put(w->mlx, w->window, (w->max_x / 2) - 80, 10, 0xFFFFFF,
		"42 - MAN for FDF");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) - 130, 50, 0xFFFFFF,
		"- You can use");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3), 50, 0x1DFF00, " WASD");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 50, 50, 0xFFFFFF,
		" or the");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 120, 50, 0x1DFF00,
		" arrows");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 190, 50, 0xFFFFFF,
		" to move the object");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) - 130, 80, 0xFFFFFF,
		"- You can use");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3), 80, 0x1DFF00, " -");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 20, 80, 0xFFFFFF, " or");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 50, 80, 0x1DFF00, " +");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 70, 80, 0xFFFFFF,
		" from the numerical keybord or not to zoom in/out");
}

void			ft_help(t_win *w)
{
	ft_help_one(w);
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) - 130, 110, 0xFFFFFF,
		"- You can use");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3), 110, 0x1DFF00, " r");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 20, 110, 0xFFFFFF,
		" or");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 50, 110, 0x1DFF00, " f");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 70, 110, 0xFFFFFF,
		" to change the value of height (Z Factor)");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) - 130, 140, 0xFFFFFF,
		"- You can use");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3), 140, 0x1DFF00,
		" 1 2 3 4");
	mlx_string_put(w->mlx, w->window, (w->max_x / 3) + 80, 140, 0xFFFFFF,
		" to rotate the object");
	mlx_string_put(w->mlx, w->window, (w->max_x / 2) - 120, 200, 0xFFFFFF,
		"Press");
	mlx_string_put(w->mlx, w->window, (w->max_x / 2) - 70, 200, 0xFF0000,
		" Q");
	mlx_string_put(w->mlx, w->window, (w->max_x / 2) - 50, 200, 0xFFFFFF,
		" to leave the man");
}
