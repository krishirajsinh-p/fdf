/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:31:49 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/10 08:30:02 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->y)
		if (map->z[i].array)
			free(map->z[i++].array);
	free(map->z);
	map->z = NULL;
}

int	main(int argc, t_string argv[])
{
	t_map	map;

	parse(argc, argv, &map);
	// map.x = map.z[0].size;
	// ft_printf("[%d] x [%d]\n", map.x, map.y);
	// for (unsigned int i = 0; i < map.y; i++)
	// {
	// 	for (unsigned int j = 0; j < map.z->size; j++)
	// 	{
	// 		ft_printf("[%d]\t", map.z[i].array[j]);
	// 	}
	// 	ft_putchar('\n');
	// }
	// free_map(&map);
	// system("leaks fdf");
	exit (EXIT_SUCCESS);
}
