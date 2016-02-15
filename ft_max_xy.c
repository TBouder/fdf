/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:17:03 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/04 14:17:51 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_max_x(t_dot *dot)
{
	int		max_x;

	max_x = 0;
	while (dot)
	{
		if (dot->x > max_x)
			max_x = dot->x;
		dot = dot->next;
	}
	return (max_x);
}

int		ft_max_y(t_dot *dot)
{
	int		max_y;

	max_y = 0;
	while (dot)
	{
		if (dot->y > max_y)
			max_y = dot->y;
		dot = dot->next;
	}
	return (max_y);
}
