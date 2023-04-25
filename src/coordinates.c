/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:30:00 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 04:06:01 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	allocate_memory(t_data *data)
{
	unsigned int	i;

	data->pts = ft_calloc(data->map.y, sizeof(t_coordinates *));
	if (data->pts == NULL)
		throw_error(MEM_ERROR);
	i = 0;
	while (i < data->map.y)
	{
		data->pts[i] = ft_calloc(data->map.x, sizeof(t_coordinates));
		if (data->pts[i] == NULL)
			throw_error(MEM_ERROR);
		i++;
	}
}

void	init_coordinates(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	allocate_memory(data);
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			data->pts[y][x].x = x + 1;
			data->pts[y][x].y = y + 1;
			data->pts[y][x].z = data->map.z[y].array[x];
			x++;
		}
		y++;
	}
}

void	free_coordinates(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->map.y)
	{
		if (data->pts[i])
			free(data->pts[i]);
		i++;
	}
	free(data->pts);
	data->pts = NULL;
}

void	space_coordinates(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = (data->i_wh[0] / data->map.x) / 2;
	y = (data->i_wh[1] / data->map.y) / 2;
	if (x < y)
		data->space = x;
	else
		data->space = y;
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			data->pts[y][x].x = x * data->space;
			data->pts[y][x].y = y * data->space;
			x++;
		}
		y++;
	}
}

void	to_isometric(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	int				x;
	int				y;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			x = data->pts[i][j].x;
			y = data->pts[i][j].y;
			data->pts[i][j].x = (x - y) * cos(data->radians);
			data->pts[i][j].y = -(data->pts[i][j].z * 2) + \
			(x + y) * sin(data->radians);
			j++;
		}
		i++;
	}
}

void	center_coordinates(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	short			x;
	short			y;

	x = (data->i_wh[0] - data->pts[data->map.y / 2][data->map.x / 2].x) / 2;
	y = (data->i_wh[1] - data->pts[data->map.y / 2][data->map.x / 2].y) / 2;
	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			data->pts[i][j].x += x;
			data->pts[i][j].y += y;
			j++;
		}
		i++;
	}
}
