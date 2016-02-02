/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:23:56 by Tbouder           #+#    #+#             */
/*   Updated: 2016/02/02 15:21:35 by tbouder          ###   ########.fr       */
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
	struct s_dot	*next;
}					t_dot;


t_dot				**ft_str_to_dot(char *str, t_dot **dot);
int					ft_max_x(char *str);


#endif
