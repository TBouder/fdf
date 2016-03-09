/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:35:53 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 17:47:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_save_origin() function saves the original coor of x, y, z.
*/

void		ft_save_origin(t_dot *dot)
{
	while (dot)
	{
		dot->o_x = dot->x;
		dot->o_y = dot->y;
		dot->o_z = dot->z;
		dot = dot->next;
	}
}

/*
** The ft_restore_origin() function loads the original coor of x, y, z.
*/

void		ft_restore_origin(t_dot *dot, t_win w)
{
	while (dot)
	{
		dot->x = dot->o_x;
		dot->y = dot->o_y;
		dot->z = dot->o_z;
		if (w.zoom_z == 0)
			dot->z = 0;
		dot = dot->next;
	}
}

/*
** The ft_extract_map() function convert the string with the datas of the map
** in chained list that we can use.
*/

void		ft_extract_map(char **str, char *s, t_dot **dot, t_coo *coo)
{
	int		y;
	int		i;

	y = 0;
	(*coo).x = 0;
	str = ft_strsplit(s, ' ');
	while (str[y])
	{
		i = 0;
		(*coo).x++;
		(*coo).z = ft_atoi_part(str[y], i);
		i += (ft_atoi_part(str[y], i) == 0) ? 1 : ft_nbrlen(ft_atoi_part(str[y],
			i));
		if (str[y][i] == ',' && str[y][i + 1] == '0' && (str[y][i + 2] == 'x'
			|| str[y][i + 2] == 'X'))
			ft_dotend(dot, (*coo), ft_atoi_hexa(&str[y][i + 3]), (*coo).x - 1);
		else
			ft_dotend(dot, (*coo), 16777215, (*coo).x - 1);
		y++;
	}
	(*coo).x = 0;
	(*coo).y++;
}

/*
** The ft_exit() function frees the memory and exits the program
*/

void		ft_exit(t_win *w)
{
	mlx_destroy_window(w->mlx, w->window);
	free(w->mlx);
	free(w->dot);
	exit(0);
}
