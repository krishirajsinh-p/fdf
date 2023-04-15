/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:29 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/15 04:22:54 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(const t_string msg, bool sys_error)
{
	if (sys_error)
		perror(msg);
	else
		ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
