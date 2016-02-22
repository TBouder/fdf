/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:35:53 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/22 18:50:16 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_nbrounded_down() function takes a number nb and returns nb rounded
** down. Tool to debug.
*/

int			ft_nbrounded_down(float nb)
{
	int		i;
	int		len;

	len = ft_nbrlen((int) nb);
	i = ft_power(10, len - 1);
	while (i < nb)
		i += 1;
	return (i - 1);
}

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
** The ft_nbrounded_down() function loads the original coor of x, y, z.
*/

void		ft_restore_origin(t_dot *dot)
{
	while (dot)
	{
		dot->x = dot->o_x;
		dot->y = dot->o_y;
		dot->z = dot->o_z;
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
		i += (ft_atoi_part(str[y], i) == 0) ? 1 : ft_nbrlen(ft_atoi_part(str[y], i));
		if (str[y][i] == ',' && str[y][i + 1] == '0' && (str[y][i + 2] == 'x' || str[y][i + 2] == 'X'))
			ft_dotend(dot, (*coo), ft_atoi_hexa(&str[y][i + 1]), (*coo).x - 1);
		else
			ft_dotend(dot, (*coo), 16777215, (*coo).x - 1);
		y++;
	}
	(*coo).x = 0;
	(*coo).y++;
}