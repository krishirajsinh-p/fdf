/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:34:16 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 04:44:10 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static double	deg_to_rad(int degree)
{
	return (degree * 3.14159265F / 180.0F);
}

void	init_static_data(t_data *data)
{
	data->map.z = NULL;
	data->pts = NULL;
	data->w = NULL;
	data->w_wh[0] = 2160;
	data->w_wh[1] = 1280;
	data->img = NULL;
	data->i_wh[0] = 2000;
	data->i_wh[1] = 1200;
	data->space = 1;
	data->radians = deg_to_rad(30);
	ft_error("data", data);
}

void	init_data(t_data *data)
{
	short	x;
	short	y;

	init_coordinates(data);
	space_coordinates(data);
	to_isometric(data);
	center_coordinates(data);
	data->w = mlx_init(data->w_wh[0], data->w_wh[1], "FdF", true);
	if (data->w == NULL)
		throw_error("mlx");
	data->img = mlx_new_image(data->w, data->i_wh[0], data->i_wh[1]);
	if (data->img == NULL)
		throw_error("mlx");
	x = (data->w_wh[0] - data->i_wh[0]) / 2;
	y = (data->w_wh[1] - data->i_wh[1]) / 2;
	if (mlx_image_to_window(data->w, data->img, x, y) < 0)
		throw_error("mlx");
}

void	free_data(t_data *data)
{
	if (data->pts)
		free_coordinates(data);
	if (data->map.z)
		free_map(&data->map);
	if (data->w)
		mlx_terminate(data->w);
}
