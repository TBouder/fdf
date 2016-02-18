/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:32:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/18 17:36:27 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** The ft_dotnew() function creates a new link with the dot datas.
*/

static t_dot		*ft_dotnew(t_coo coo, int color, int id)
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

static void			ft_dotend(t_dot **dot, t_coo coo, int color, int id)
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

static int			ft_extract_color(char *str, int i)
{
	int		j;
	int		k;

	k = 0;
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
** The ft_str_to_dot() function is a little helper because of the norm.
*/

static int			ft_str_to_dot_helper(char *str)
{
	int		i;

	i = 0;
	if (str[i] == ',')
	{
		while (str[i] != ' ')
			i++;
	}
	else
		i++;
	return (i);
}

/*
** The ft_str_to_dot() function extract the grid and the elems as a linked
** list, with, for each dot, X, Y, Z, COLOR.
*/

t_dot				**ft_str_to_dot(char *str, t_dot **dot, int id)
{
	t_coo	coo;
	int		i;

	i = 0;
	coo.x = 0;
	coo.y = 1;
	while (str[i])
	{
		if (ft_isnumber(str[i]) || str[i] == '-')
		{
			coo.x++;
			coo.z = ft_atoi_part(str, i);
			ft_dotend(dot, coo, ft_extract_color(str, i), id++);
			i += (ft_atoi_part(str, i) == 0) ? 1 :
				ft_nbrlen(ft_atoi_part(str, i));
		}
		if (str[i] == '\n')
		{
			coo.x = 0;
			coo.y++;
		}
		i += ft_str_to_dot_helper(&str[i]);
	}
	return (dot);
}