/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:31:49 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 05:37:03 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

//dyanamic z factor and resize map if too big
//shorten draw_line or split or make data strcuture for it and call init func

int	main(int argc, t_string argv[])
{
	t_data	data;

	init_static_data(&data);
	init_map(argc, argv, &data.map);
	init_data(&data);
	draw_map(&data);
	if (mlx_loop_hook(data.w, ft_hook, &data))
		mlx_loop(data.w);
	free_data(&data);
	system("leaks fdf");	//remove
	exit (EXIT_SUCCESS);
}
