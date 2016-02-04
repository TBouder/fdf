/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/03 17:27:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <stdio.h>//

int		ft_dotlen(t_dot *begin_dot)
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

char	*ft_extract_map(char *file, int fd)
{
	char	buffer;
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0)
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (!(string = (char *)malloc(sizeof(char *) * (i + 1))) && fd != -1)
		return (NULL);
	while (read(fd, &buffer, 1) > 0)
		string[j++] = buffer;
	close(fd);
	string[j] = '\0';
	return (string);
}

/*-----MAX_X_Y------*/

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

/*-----PLACE&LINK DOTS------*/

void		ft_place_dots(t_win w, t_dot *dot)
{
	int		x;
	int		y;

	while (dot)
	{
			// dot->x += ZOOM;
			// dot->y += ZOOM;
		// x = w.max_x / 2 +			(dot->x - dot->y) * (ZOOM / 2);
		// y = ZOOM+					(dot->x + dot->y) * (ZOOM / 2);

		// x = w.max_x / 2 +		(dot->x - dot->z) * tan(30);
		// y = w.max_y / 2 +		(dot->y) + (dot->x + dot->z) * tan(30);
		
		// x = cos(30);
		// y = sin(30);
		
		x = dot->x * ZOOM - dot->z * ZOOM;
		y = dot->y * ZOOM;
		mlx_pixel_put(w.mlx, w.window, x, y, dot->color);
		dot = dot->next;
	}
}

void		ft_link_dots_x(t_win w, t_dot *dot)
{
	t_dot	*doot;
	int		i;
	int		j;

	doot = dot;
	i = 0;
	j = 0;
	while (i < ft_dotlen(doot) - 1)
	{
		if (dot->next->x != 0 && dot->next->z == 0)
		{
			j = (dot->x * ZOOM);
			while (j < (dot->next->x * ZOOM))
				mlx_pixel_put(w.mlx, w.window, j++, ((dot->y) * ZOOM), dot->color);
		}
		dot = dot->next;
		i++;
	}
}

void		ft_link_dots_y(t_win w, t_dot *dot)
{
	t_dot	*doot;
	int		j;
	int		previous_y;

	doot = dot;
	previous_y = dot->y;
	while (dot)
	{
		if (dot->y != previous_y)
		{
			j = (previous_y * ZOOM);
			while (j < (dot->y * ZOOM))
				mlx_pixel_put(w.mlx, w.window, ((dot->x) * ZOOM), j++, dot->color);
			previous_y = dot->y;
		}
		dot = dot->next;
	}
	dot = doot;
	doot = doot->next;
}


/*-----------*/

void		window(char *name, t_dot *dot)
{
	t_win	w;

	w.mlx = mlx_init();
	w.name = name;
	w.max_x = (ZOOM + 2) * ft_max_x(dot) * 3;
	w.max_y = (ZOOM + 2) * ft_max_y(dot) * 3;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);

	ft_place_dots(w, dot);
	ft_link_dots_x(w, dot);
	ft_link_dots_y(w, dot);
	mlx_loop(w.mlx);
}

void		ft_dotprint(t_dot *begin_dot)
{
	int		i;

	i = 0;
	while (begin_dot)
	{
		ft_putstr("Dot n_");
		ft_putnbr(begin_dot->id);
		ft_putstr(" : x-");
		ft_putnbr(begin_dot->x);
		ft_putstr(" | y-");
		ft_putnbr(begin_dot->y);
		ft_putstr(" | z-");
		ft_putnbr(begin_dot->z);
		ft_putstr(" | color-");
		ft_nbrendl(begin_dot->color);
		begin_dot = begin_dot->next;
	}
}

int			main(int ac, char **av)
{
	int		fd;
	char	*str;
	t_dot	*dot = NULL;

	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		str = ft_extract_map(av[1], fd);
		ft_str_to_dot(str, &dot, 0);
		ft_dotprint(dot);
		window(av[1], dot);
		// printf("%d\n", ft_max_x(dot));
	}
	return (0);
}
