/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/18 18:07:38 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_dotprint(t_dot *begin_dot)
{
	while (begin_dot->next)
	{
		// ft_putstr("Dot n_");
		// ft_putnbr(begin_dot->id);
		// ft_putstr(" : x = ");
		// ft_putnbr(begin_dot->x);
		// ft_putstr(" | y = ");
		// ft_putnbr(begin_dot->y);
		// ft_putstr(" | z = ");
		ft_putnbr(begin_dot->z);
		ft_putstr("  ");
		// ft_putstr(" | color = ");
		// ft_nbrendl(begin_dot->color);
		begin_dot = begin_dot->next;
		if (begin_dot->id % 19 == 0 && begin_dot->id != 1)
			ft_putchar('\n');

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
	w.mlx = mlx_init(); //PROTEGER
	w.name = name;
	w.max_x = 1000;
	w.max_y = 1000;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);

	ft_place_dots(w, dot);
	ft_link_one(w, dot, max_x);
	ft_link_two(w, dot, max_x);

	// ft_link_down_to_up_h(w, dot);
	// ft_link_up_to_down_h(w, dot);
	// ft_link_down_to_up_v(w, dot, max_x);
	
	mlx_loop(w.mlx);
}

int			main(int ac, char **av)
{
	int		fd;
	int		y;
	char	*str;
	t_dot	*dot = NULL;

	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		y = 1;
		while (get_next_line(fd, &str))
		{
			ft_str_to_dot(str, &dot, 0, y++);
			printf("%s\n", str);
			free(str);
			str = NULL;
		}
		window(av[1], dot);
	}
	return (0);
}
