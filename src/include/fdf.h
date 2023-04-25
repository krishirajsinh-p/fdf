/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:18:16 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 04:03:44 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../lib/mlx42/include/MLX42/MLX42.h"
# include "../../lib/libft/libft.h"
# include <math.h>
# include <fcntl.h>

# define FORMAT_ERROR "fdf: illegal command\n\
usage:\t./fdf [<relative-address-of-map>]\n\
eg:\t./fdf maps/42.fdf"

# define EXT_ERROR "ERROR: provide a map file with \".fdf\" extension."

# define MTY_ERROR "ERROR: map file is empty"

# define MEM_ERROR "ERROR: memory allocation failed."

# define MAP_ERROR "ERROR: map is not properly formatted, \
every line should have same number of values."

typedef struct s_array
{
	int				*array;
	unsigned int	size;
}	t_array;

typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	t_array			*z;
}	t_map;

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}	t_coordinates;

typedef struct s_data
{
	t_map			map;
	t_coordinates	**pts;
	mlx_t			*w;
	unsigned int	w_wh[2];
	mlx_image_t		*img;
	unsigned int	i_wh[2];
	short			space;
	double			radians;
}	t_data;

//====data.c====
void			init_static_data(t_data *data);
void			init_data(t_data *data);
void			free_data(t_data *data);

//====map.c====
void			init_map(int argc, t_string argv[], t_map *map);

//====map2.c====
void			free_map(t_map *map);
void			free_split(t_string split[]);
unsigned int	count_elements(t_string split[]);

//====coordinates.c====
void			init_coordinates(t_data *data);
void			free_coordinates(t_data *data);
void			space_coordinates(t_data *data);
void			to_isometric(t_data *data);
void			center_coordinates(t_data *data);

//====mlx.c====
void			draw_map(t_data *data);
void			ft_hook(void *param);

//====ft_error.c====
void			throw_error(t_string msg);
void			ft_error(t_string msg, t_data *rec_data);

#endif
