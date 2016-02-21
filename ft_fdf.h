/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:23:56 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/21 19:46:00 by Tbouder          ###   ########.fr       */
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

# define ZOOM 15
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
	int				y;
	int				z;
	int				color;
	int				id;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_win
{
	void			*mlx;
	void			*window;
	int				max_x;
	int				max_y;
	char			*name;
}					t_win;

t_dot				**ft_str_to_dot(char *str, t_dot **dot, int id);
t_dot				**ft_str_to_dotGNL(char *str, t_dot **dot, int id, int y); //
t_dot				**ft_str_dot(char *str, t_dot **dot, int y, int id); //

t_dot				*ft_dotnew(t_coo coo, int color, int id);
void				ft_dotend(t_dot **dot, t_coo coo, int color, int id);
int					ft_extract_color(char *str, int i);


int					ft_max_x(t_dot *dot);
int					ft_max_y(t_dot *dot);

void				ft_place_dots(t_win w, t_dot *dot);
void				ft_link_one(t_win w, t_dot *dot, int max_x);
void				ft_link_two(t_win w, t_dot *dot, int max_x);

#endif
