/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:55:45 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/10 01:10:28 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static t_array	to_int_arr(t_string split[]);
static unsigned int	get_y(t_string map_file);
static void	get_map(t_string map_file, t_map *map);

static void	free_2d_arr(t_string split[])
{
	unsigned int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static unsigned int	len_2d_arr(t_string split[])
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

	if (split == NULL)
		return (arr);
	arr.size = len_2d_arr(split);
	arr.array = (int *) ft_calloc(arr.size, sizeof(int));
	if (arr.array == NULL)
		return (arr);
	i = 0;
	while (i < arr.size)
	{
		arr.array[i] = ft_atoi(split[i]);
		i++;
	}
	free_2d_arr(split);
	return (arr);
}

static void	get_map(t_string map_file, t_map *map)
{
	int				fd;
	unsigned int	i;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->y)
	{
		map->z[i] = to_int_arr(ft_split(get_next_line(fd), ' '));
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
	if (argc != 2)
		ft_error(FORMAT_ERROR);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4) != 0)
		ft_error(MAP_ERROR);
	map->y = get_y(argv[1]);
	map->z = (t_array *) ft_calloc(map->y, sizeof(t_array));
	if (map->z == NULL)
		ft_error(MEM_ERROR);
	get_map(argv[1], map);
}
