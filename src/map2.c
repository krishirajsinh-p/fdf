/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:56:55 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/22 23:49:09 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	free_split(t_string split[])
{
	unsigned int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

unsigned int	count_elements(t_string split[])
{
	unsigned int	count;

	count = 0;
	while (split[count] && ft_strncmp(split[count], "\n", 1))
		count++;
	return (count);
}

void	free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->y)
	{
		if (map->z[i].array)
			free(map->z[i].array);
		i++;
	}
	free(map->z);
	map->z = NULL;
}
