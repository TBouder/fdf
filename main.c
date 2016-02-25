/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/25 11:50:15 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_dotprint(t_dot *begin_dot) //TO DELETE
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

/*-----------*/

int				ft_putkey(int keycode, t_win *w)
{

	ft_putstr("key event ");
	ft_nbrendl(keycode);
	if (keycode == 24 || keycode == 69 || keycode == 27 || keycode == 78
		|| keycode == 123 || keycode == 0 || keycode == 124 || keycode == 2
		|| keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13
		|| keycode == 15 || keycode == 3)
	{
		mlx_clear_window(w->mlx, w->window);
		keycode == 24 || keycode == 69 ? w->zoom += 1 : 0;
		keycode == 27 || keycode == 78 ? w->zoom -= 1 : 0;

		keycode == 123 || keycode == 0 ? w->obj_x -= 10 : 0;
		keycode == 124 || keycode == 2 ? w->obj_x += 10 : 0;
		keycode == 125 || keycode == 1 ? w->obj_y += 10 : 0;
		keycode == 126 || keycode == 13 ? w->obj_y -= 10 : 0;

		keycode == 15 ? w->zoom_z += ZOOM : 0;
		keycode == 3 ? w->zoom_z -= ZOOM : 0;

		ft_create_fdf(*w, 1);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(w->mlx, w->window);
		free(w->mlx);
		exit(0);
	}
	return (1);
}

void		window(char *name, t_dot *dot)
{
	t_win	w;
	int		y;

	w.x = ft_max_x(dot);
	y = ft_max_y(dot);
	w.mlx = mlx_init(); //PROTEGER
	w.name = name;
	w.zoom = ZOOM;
	w.zoom_z = ZOOM;
	w.max_x = 1000;
	w.max_y = 1000;
	w.obj_x = 0;
	w.obj_y = 500;
	w.dot = dot;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);
	ft_create_fdf(w, 0);
	mlx_key_hook(w.window, ft_putkey, &w);
	mlx_loop(w.mlx);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*s;
	char	**str;
	t_coo	coo;
	t_dot	*dot;

	s = NULL;
	str = NULL;
	dot = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		coo.y = 1;
		while (get_next_line(fd, &s))
			ft_extract_map(str, s, &dot, &coo);
		ft_save_origin(dot);
		window(av[1], dot);
	}
	ft_strdel(&s);
	ft_strdel(str);
	return (0);
}
