/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:43:32 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 03:21:05 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void draw_line(mlx_image_t *img, t_coordinates *pt1, t_coordinates *pt2)
{
	int		dx;
	int		dy;
	short	sx;
	short	sy;
	int		err;
	int x = pt1->x;
	int y = pt1->y;

	dx = abs(pt2->x - pt1->x);
	dy = abs(pt2->y - pt1->y);
	sx = pt2->x < pt1->x ? -1 : 1;
	sy = pt2->y < pt1->y ? -1 : 1;
	err = dx - dy;

	while (x != pt2->x || y != pt2->y)
	{
		mlx_put_pixel(img, x, y, 0xffffffff);
		int err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void draw_map(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			if (j != data->map.x - 1)
				draw_line(data->img, &data->pts[i][j], &data->pts[i][j+1]);
			if (i != data->map.y - 1)
				draw_line(data->img, &data->pts[i][j], &data->pts[i+1][j]);
			j++;
		}
		i++;
	}
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (mlx_is_key_down(data->w, MLX_KEY_ESCAPE))
		mlx_close_window(data->w);
}
