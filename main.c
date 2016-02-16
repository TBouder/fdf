/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/16 21:30:28 by Tbouder          ###   ########.fr       */
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
	while (begin_dot->next)
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

/*-----------*/

void		window(char *name, t_dot *dot)
{
	t_win	w;
	int		max_x;

	max_x = ft_max_x(dot);
	w.mlx = mlx_init();
	w.name = name;
	w.max_x = 1000;
	w.max_y = 1000;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);

	ft_place_dots(w, dot);
	ft_link_one(w, dot);
	ft_link_two(w, dot, max_x);

	// ft_link_down_to_up_h(w, dot);
	// ft_link_up_to_down_h(w, dot);
	// ft_link_down_to_up_v(w, dot, max_x);
	
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
		window(av[1], dot);
	}
	return (0);
}
