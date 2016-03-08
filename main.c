/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/08 16:51:25 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*
** BONUS :
** Deplacement de l'object (gauche, droite, haut, bas)
** Zoom/Dezoom de l'objet
** Zoom/Dezoom de la hauteur individuellement
** Affichage d'informations relatives a l'objet en haut a gauche
*/

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

int				ft_putkey(int key, t_win *w)
{
	ft_putstr("key event ");
	ft_nbrendl(key);
	if ((key >= 18 && key <= 21) || (key >= 123 && key <= 126)
	|| (key >= 0 && key <= 3) || key == 13 || key == 15 || key == 24
	|| key == 69 || key == 27 || key == 78)
	{
		mlx_clear_window(w->mlx, w->window);
		key == 24 || key == 69 ? w->zoom += 1 : 0;
		key == 27 || key == 78 ? w->zoom -= 1 : 0;
		key == 123 || key == 0 ? w->obj_x -= 10 : 0;
		key == 124 || key == 2 ? w->obj_x += 10 : 0;
		key == 125 || key == 1 ? w->obj_y += 10 : 0;
		key == 126 || key == 13 ? w->obj_y -= 10 : 0;
		key == 15 ? w->zoom_z += 1 : 0;
		key == 3 ? w->zoom_z -= 1 : 0;
		key == 18 ? w->rotation = 1 : 0;
		key == 19 ? w->rotation = 2 : 0;
		key == 20 ? w->rotation = 3 : 0;
		key == 21 ? w->rotation = 4 : 0;
		ft_create_fdf(*w, 1);
	}
	if (key == 53)
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
	w.zoom_z = 1;
	w.max_x = 1000;
	w.max_y = 1000;
	w.obj_x = 0;
	w.obj_y = 500;
	w.rotation = 1;
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
