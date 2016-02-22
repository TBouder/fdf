/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:23:56 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/22 17:25:44 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <errno.h>
# include <string.h>
# include <math.h>

# include <stdio.h>//

# define ZOOM 14
# define POS_X 0
# define POS_Y (w.max_y / 2)

typedef struct		s_coo
{
	int				x;
	int				y;
	int				z;
}					t_coo;

typedef struct		s_dot
{
	int				x;
	int				o_x;
	int				y;
	int				o_y;
	int				z;
	int				o_z;
	int				color;
	int				id;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_win
{
	void			*mlx;
	void			*window;
	char			*name;
	int				max_x;
	int				max_y;
	int				zoom;
	t_dot			*dot;
}					t_win;

t_dot				*ft_dotnew(t_coo coo, int color, int id);
void				ft_dotend(t_dot **dot, t_coo coo, int color, int id);
int					ft_extract_color(char *str, int i);
t_dot				*ft_dotnext(t_dot *dot, int n);

int					ft_max_x(t_dot *dot);
int					ft_max_y(t_dot *dot);

void				ft_place_dots(t_win w, t_dot *dot);
void				ft_link_one(t_win w, t_dot *dot, int max_x);
void				ft_link_two(t_win w, t_dot *dot, int max_x);

#endif
