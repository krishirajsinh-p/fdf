/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:31:49 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/15 21:03:33 by kpuwar           ###   ########.fr       */
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

	map.z = NULL;
	parse(argc, argv, &map);
	free_map(&map);
	exit (EXIT_SUCCESS);
}

/*
ft_printf("x:[%d] y:[%d]\n", map.x, map.y);
for (unsigned int i = 0; i < map.y; i++)
{
	for (unsigned int j = 0; j < map.x; j++)
		printf("%d ", map.z[i].array[j]);
	printf("\n");
}

system("leaks fdf");
*/