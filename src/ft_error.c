/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:29 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/25 03:26:22 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	throw_error(t_string msg)
{
	ft_error(msg, NULL);
}

void	ft_error(t_string msg, t_data *rec_data)
{
	static t_data	*data;

	if (rec_data != NULL && ft_strncmp("data", msg, 4) == 0)
		data = rec_data;
	else
	{
		free_data(data);
		if (msg == NULL)
			perror("ERROR");
		else if (ft_strncmp("mlx", msg, 3) == 0)
			ft_putendl_fd((char *) mlx_strerror(mlx_errno), 2);
		else
			ft_putendl_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
}
