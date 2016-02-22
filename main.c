/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/22 17:58:06 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_dotprint(t_dot *begin_dot) //
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

void		ft_save_origin(t_dot *dot)
{
	while (dot->next)
	{
		dot->o_x = dot->x;
		dot->o_y = dot->y;
		dot->o_z = dot->z;
		dot = dot->next;
	}	
}

void		ft_restore_origin(t_dot *dot)
{
	while (dot->next)
	{
		dot->x = dot->o_x;
		dot->y = dot->o_y;
		dot->z = dot->o_z;
		dot = dot->next;
	}	
}

void		ft_place_dots(t_win w, t_dot *dot)
{
	float		x;
	float		y;
	int			i;

	while (dot)
	{
		i = -1;
		x = (dot->x + dot->y) * w.zoom;
		y = (dot->y - dot->x) * w.zoom - (dot->z * w.zoom * 2.7);
		while (i++ < w.zoom)
		{
			if (ft_dotnext(dot, w.x_max) && ft_dotnext(dot, w.x_max)->z == dot->z)
				mlx_pixel_put(w.mlx, w.window, (POS_X) + (x + i), (POS_Y) +
					(y + i) * sin(30 * (PI / 180)), 16777215);

			if (dot->next && dot->x % w.x_max != 0 && dot->next->z == dot->z)
				mlx_pixel_put(w.mlx, w.window, (POS_X) + (x + i), (POS_Y) +
					(y - i) * sin(30 * (PI / 180)), 16777215);
		}
		dot->x = lroundf((POS_X) + (x));
		dot->y = lroundf((POS_Y) + (y) * sin(30 * (PI / 180)));
		dot = dot->next;
	}
}

void		ft_create_fdf(t_win w, int i)
{
	if (i == 1)
	{
		// ft_dotprint(w.dot);
		// printf("%d\n", w.x_max);
		// printf("------------\n");
		ft_restore_origin(w.dot);
		// ft_dotprint(w.dot);
		// printf("%d\n", w.x_max);

		printf("\n\n\n");
	}

	ft_place_dots(w, w.dot);
	ft_link_one(w, w.dot, w.x_max);
	ft_link_two(w, w.dot, w.x_max);
}

int				ft_putkey(int keycode, t_win *w)
{

	// printf("%d\n", w->zoom);
	ft_putstr("key event ");
	ft_nbrendl(keycode);
	if (keycode == 24)
	{
		mlx_clear_window(w->mlx, w->window);
		w->zoom += 1;
		ft_create_fdf(*w, 1);
	}
	return (1);
}

void		window(char *name, t_dot *dot)
{
	t_win	w;

	w.x_max = ft_max_x(dot);
	w.mlx = mlx_init(); //PROTEGER
	w.name = name;
	w.max_x = 500;
	w.max_y = 500;
	w.zoom = ZOOM;
	w.dot = dot;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);
	ft_create_fdf(w, 0);


	mlx_key_hook(w.window, ft_putkey, &w);
	mlx_loop(w.mlx);
}

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

int			main(int ac, char **av)
{
	int		fd;
	char	*s;
	char	**str;
	t_coo	coo;
	t_dot	*dot = NULL;

	s = NULL;
	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		coo.y = 1;
		while (get_next_line(fd, &s))
			ft_extract_map(str, s, &dot, &coo);
	}
	if (dot != NULL)
	{
		ft_save_origin(dot);
		window(av[1], dot);
	}
	return (0);
}
