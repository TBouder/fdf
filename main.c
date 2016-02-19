/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:32:25 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/19 13:27:45 by Tbouder          ###   ########.fr       */
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
	w.mlx = mlx_init(); //PROTEGER
	w.name = name;
	w.max_x = 1900;
	w.max_y = 1000;
	w.window = mlx_new_window(w.mlx, w.max_x, w.max_y, w.name);

	ft_place_dots(w, dot);
	ft_link_one(w, dot, max_x);
	ft_link_two(w, dot, max_x);
	mlx_loop(w.mlx);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*s;
	char	**str;
	t_dot	*dot = NULL;

	s = NULL;
	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		//---------------
		int		y;
		int		i;
		int		id;
		t_coo	coo;

		y = 0;
		id = 0;
		coo.x = 0;
		coo.y = 1;
		while (get_next_line(fd, &s))
		{
			//----------A METTRE DANS UNE FONCTION A PART-----------//
			str = ft_strsplit(s, ' ');
			while (str[y])
			{
				i = 0;
				coo.x++;
				coo.z = ft_atoi_part(str[y], i);
				i += (ft_atoi_part(str[y], i) == 0) ? 1 : ft_nbrlen(ft_atoi_part(str[y], i));
				if (str[y][i] == ',' && str[y][i + 1] == '0' && (str[y][i + 2] == 'x' || str[y][i + 2] == 'X'))
					ft_dotend(&dot, coo, ft_atoi_hexa(&str[y][i + 1]), id++);
				else
					ft_dotend(&dot, coo, 16777215, id++);
				y++;
			}
			y = 0;
			coo.x = 0;
			coo.y++;
			//---------------------//

		}
			ft_dotprint(dot);

		//---------------
		// str = ft_extract_map(av[1], fd);
		// ft_str_to_dot(str, &dot, 0);
		// printf("%s\n", str);
	}
	if (dot != NULL)
		window(av[1], dot);
	return (0);
}
