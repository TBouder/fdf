/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:23:56 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/09 16:09:23 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define ZOOM 15

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
	int				obj_x;
	int				obj_y;
	int				zoom;
	int				zoom_z;
	int				x;
	int				rotation;
	t_dot			*dot;
}					t_win;

/*
** In ft_dot_struct
*/

t_dot				*ft_dotnew(t_coo coo, int color, int id);
void				ft_dotend(t_dot **dot, t_coo coo, int color, int id);
int					ft_extract_color(char *str, int i);
t_dot				*ft_dotnext(t_dot *dot, int n);

/*
** In ft_max_xy
*/

int					ft_max_x(t_dot *dot);
int					ft_max_y(t_dot *dot);

/*
** In ft_link_[roots, one, two]
*/

void				ft_create_fdf(t_win w, int i);
void				ft_place_dots_1(t_win w, t_dot *dot);
void				ft_link_one_1(t_win w, t_dot *dot);
void				ft_link_two_1(t_win w, t_dot *dot);
void				ft_place_dots_2(t_win w, t_dot *dot);
void				ft_link_one_2(t_win w, t_dot *dot);
void				ft_link_two_2(t_win w, t_dot *dot);
void				ft_place_dots_3(t_win w, t_dot *dot);
void				ft_link_one_3(t_win w, t_dot *dot);
void				ft_link_two_3(t_win w, t_dot *dot);
void				ft_place_dots_4(t_win w, t_dot *dot);
void				ft_link_one_4(t_win w, t_dot *dot);
void				ft_link_two_4(t_win w, t_dot *dot);

/*
** In ft_tools
*/

void				ft_extract_map(char **str, char *s, t_dot **dot,
						t_coo *coo);
void				ft_save_origin(t_dot *dot);
void				ft_restore_origin(t_dot *dot);
void				ft_exit(t_win *w);

/*
** In ft_help
*/
void				ft_help(t_win *w);

#endif
