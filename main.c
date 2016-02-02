/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/02 19:00:56 by tbouder          ###   ########.fr       */
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

void		ft_place_dots(void *mlx, void *win, t_dot *dot)
{
	while (dot)
	{
		mlx_pixel_put(mlx, win, ((dot->x) * 28), ((dot->y) * 28), dot->color);
		dot = dot->next;
	}
}

void		ft_link_dots_x(void *mlx, void *win, t_dot *dot)
{
	t_dot	*doot;
	int		i;
	int		j;

	doot = dot;
	i = 0;
	j = 0;
	while (i < ft_dotlen(doot) - 1)
	{
		if (dot->next->x != 0)
		{
			j = (dot->x * 28);
			while (j < (dot->next->x * 28))
				mlx_pixel_put(mlx, win, j++, ((dot->y) * 28), dot->color);
		}
		dot = dot->next;
		i++;
	}
}

void		ft_link_dots_y(void *mlx, void *win, t_dot *dot)
{
	t_dot	*doot;
	int		i;
	int		j;

	doot = dot;
	i = 0;
	j = 0;
	while (i < ft_dotlen(doot) - 1)
	{
		if (dot->next->y == dot->y)
		{
			j = (dot->y * 28);
			while (j < (dot->next->y * 28))
				mlx_pixel_put(mlx, win, ((dot->x) * 28), j++, dot->color);
		}
		dot = dot->next;

		i++;
	}
}

void		window(char *name, t_dot *dot)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 400, name);
	ft_place_dots(mlx, win, dot);
	ft_link_dots_x(mlx, win, dot);
	ft_link_dots_y(mlx, win, dot);
	mlx_loop(mlx);
}




void		ft_dotprint(t_dot *begin_dot)
{
	int		i;

	i = 0;
	while (begin_dot)
	{
		ft_putstr("Dot n_");
		ft_putnbr(i++);
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
		ft_str_to_dot(str, &dot);
		ft_dotprint(dot);
		window(av[1], dot);
	}
	return (0);
}
