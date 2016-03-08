/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:32:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/08 13:36:39 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_dotnew() function creates a new link with the dot datas.
*/

t_dot			*ft_dotnew(t_coo coo, int color, int id)
{
	t_dot	*dot;

	if (!(dot = (t_dot *)malloc(sizeof(t_dot))))
		return (NULL);
	dot->color = color;
	dot->x = coo.x;
	dot->y = coo.y;
	dot->z = coo.z;
	dot->id = id;
	dot->next = NULL;
	return (dot);
}

/*
** The ft_dotend() function push the link at the end of the chained list.
*/

void			ft_dotend(t_dot **dot, t_coo coo, int color, int id)
{
	t_dot	*new_dot;

	new_dot = *dot;
	if (new_dot)
	{
		while (new_dot->next != NULL)
			new_dot = new_dot->next;
		new_dot->next = ft_dotnew(coo, color, id);
	}
	else
		*dot = ft_dotnew(coo, color, id);
}

/*
** The ft_extract_color() function extract the color of the dot.
*/

int				ft_extract_color(char *str, int i)
{
	int		j;

	if (ft_atoi_part(str, i) == 0)
		i++;
	else
		i += ft_nbrlen(ft_atoi_part(str, i));
	j = i;
	if (str[j++] == ',')
	{
		if (str[j] == '0')
			j++;
		if (str[j] == 'x')
			j++;
		return (ft_atoi_hexa(&str[j]));
	}
	else
		return (16777215);
}

/*
** The ft_dotnext() function jump to the n next link of the chained list dot.
*/

t_dot			*ft_dotnext(t_dot *dot, int n)
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
