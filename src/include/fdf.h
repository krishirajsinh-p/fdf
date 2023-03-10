/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:18:16 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/10 08:00:04 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../lib/mlx42/include/MLX42/MLX42.h"
# include "../../lib/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define FORMAT_ERROR "client: illegal command\n\
usage:\t./fdf [<relative-address-of-map>]\n\
eg:\t./fdf maps/42.fdf\n"

# define EXT_ERROR "Error: a map file should have \".fdf\" extension.\n"

# define MEM_ERROR "Error: memory allocation failed.\n"

# define MAP_ERROR "Error: map is not properly formatted.\n"

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