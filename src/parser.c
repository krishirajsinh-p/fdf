/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:55:45 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/10 08:17:06 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	free_split(t_string split[])
{
	unsigned int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static unsigned int	count_split(t_string split[])
{
	unsigned int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static unsigned int	get_y(t_string map_file)
{
	int				fd;
	unsigned int	count;
	t_string		line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
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
	arr.size = count_split(split);
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

static void	get_map(t_string map_file, t_map *map)
{
	int				fd;
	unsigned int	i;
	t_string		line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->y)
	{
		line = get_next_line(fd);
		map->z[i] = to_int_arr(ft_split(line, ' '));
		free(line);
		if (map->z[i].array == NULL)
		{
			free_map(map);
			ft_error(MEM_ERROR);
		}
		i++;
	}
	close(fd);
}

void	parse(int argc, t_string argv[], t_map *map)
{
	unsigned int	i;

	if (argc != 2)
		ft_error(FORMAT_ERROR);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4) != 0)
		ft_error(EXT_ERROR);
	map->y = get_y(argv[1]);
	map->z = (t_array *) ft_calloc(map->y, sizeof(t_array));
	if (map->z == NULL)
		ft_error(MEM_ERROR);
	get_map(argv[1], map);
	map->x = map->z[0].size;
	i = 0;
	while (i < map->y)
		if (map->z[i++].size != map->x)
			ft_error(MAP_ERROR);
}
