/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:23:56 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/03 13:39:20 by tbouder          ###   ########.fr       */
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

# define ZOOM 28
# define PI 3.14159265

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


#endif
