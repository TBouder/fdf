/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/16 15:46:27 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

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

void		ft_dotprint(t_dot *begin_dot)
{
	int		i;

	i = 0;
	while (begin_dot)
	{
		ft_putstr("Dot n_");
		ft_putnbr(begin_dot->id);
		ft_putstr(" : x = ");
		ft_putnbr(begin_dot->x);
		ft_putstr(" | y = ");
		ft_putnbr(begin_dot->y);
		ft_putstr(" | z = ");
		ft_putnbr(begin_dot->z);
		ft_putstr(" | color = ");
		ft_nbrendl(begin_dot->color);
		begin_dot = begin_dot->next;
	}
}

/*-----------*/

void		window(char *name, t_dot *dot)
{
	t_win	w;

	w.mlx = mlx_init();
	w.name = name;
	// w.max_x = (ZOOM + 2) * ft_max_x(dot) * 3;
	// w.max_y = (ZOOM + 2) * ft_max_y(dot) * 3;
	w.max_x = 600;
	w.max_y = 600;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);

	ft_place_dots(w, dot);
	// ft_link_down_to_up(w, dot);
	ft_place_height_second(w, dot);
	// ft_dotprint(dot);

	mlx_loop(w.mlx);
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
		// ft_dotprint(dot);
		window(av[1], dot);
		// printf("%d\n", ft_max_x(dot));
	}
	return (0);
}
