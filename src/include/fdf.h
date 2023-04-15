/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:18:16 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/15 04:42:12 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../lib/mlx42/include/MLX42/MLX42.h"
# include "../../lib/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define FORMAT_ERROR "fdf: illegal command\n\
usage:\t./fdf [<relative-address-of-map>]\n\
eg:\t./fdf maps/42.fdf\n"

# define EXT_ERROR "ERROR: provide a map file with \".fdf\" extension.\n"

# define MEM_ERROR "ERROR: memory allocation failed.\n"

# define MAP_ERROR "ERROR: map is not properly formatted, \
every line should have same number of values.\n"

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

void	parse(int argc, t_string argv[], t_map *map);
void	free_map(t_map *map);

#endif