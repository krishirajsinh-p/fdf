/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:55:45 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 03:05:34 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static unsigned int	get_y(t_string map_file)
{
	short			fd;
	unsigned int	count;
	t_string		line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		throw_error(NULL);
	count = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

static t_array	to_int_arr(t_string split[])
{
	unsigned int	i;
	t_array			arr;

	arr.array = NULL;
	if (split == NULL)
		return (arr);
	arr.size = count_elements(split);
	arr.array = ft_calloc(arr.size, sizeof(int));
	if (arr.array == NULL)
		return (arr);
	i = 0;
	while (i < arr.size)
	{
		arr.array[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	return (arr);
}

static void	get_z(t_string map_file, t_map *map)
{
	short			fd;
	unsigned int	i;
	t_string		line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		throw_error(NULL);
	i = 0;
	while (i < map->y)
	{
		line = get_next_line(fd);
		map->z[i] = to_int_arr(ft_split(line, ' '));
		if (line)
			free(line);
		if (map->z[i].array == NULL)
			throw_error(MEM_ERROR);
		i++;
	}
	close(fd);
}

static void	check_map(t_map *map)
{
	unsigned int	i;

	i = 1;
	while (i < map->y)
	{
		if (map->z[i].size != map->x)
			throw_error(MAP_ERROR);
		i++;
	}
}

void	init_map(int argc, t_string argv[], t_map *map)
{
	t_string	map_file;

	if (argc != 2)
		throw_error(FORMAT_ERROR);
	map_file = argv[1];
	if (ft_strncmp(map_file + ft_strlen(map_file) - 4, ".fdf", 4) != 0)
		throw_error(EXT_ERROR);
	map->y = get_y(map_file);
	map->z = ft_calloc(map->y, sizeof(t_array));
	if (map->z == NULL)
		throw_error(MEM_ERROR);
	get_z(map_file, map);
	map->x = map->z[0].size;
	if (map->y == 0 || map->x == 0)
		throw_error(MTY_ERROR);
	check_map(map);
}
