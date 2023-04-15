/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:55:45 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/15 20:36:27 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static unsigned int	get_y(t_string map_file)
{
	short			fd;
	unsigned int	count;
	t_string		line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR", true);
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
	arr.array = (int *) ft_calloc(arr.size, sizeof(int));
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
	if (fd == -1)
		ft_error("ERROR", true);
	i = 0;
	while (i < map->y)
	{
		line = get_next_line(fd);
		map->z[i] = to_int_arr(ft_split(line, ' '));
		if (line)
			free(line);
		if (map->z[i].array == NULL)
		{
			free_map(map);
			ft_error(MEM_ERROR, false);
		}
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
		{
			free_map(map);
			ft_error(MAP_ERROR, false);
		}
		i++;
	}
}

void	parse(int argc, t_string argv[], t_map *map)
{
	t_string	map_file;

	if (argc != 2)
		ft_error(FORMAT_ERROR, false);
	map_file = argv[1];
	if (ft_strncmp(map_file + ft_strlen(map_file) - 4, ".fdf", 4) != 0)
		ft_error(EXT_ERROR, false);
	map->y = get_y(map_file);
	map->z = (t_array *) ft_calloc(map->y, sizeof(t_array));
	if (map->z == NULL)
		ft_error(MEM_ERROR, false);
	get_z(map_file, map);
	map->x = map->z[0].size;
	check_map(map);
}
