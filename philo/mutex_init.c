/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:46:01 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/17 17:41:23 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_global *g_data, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (pthread_mutex_init(&g_data->fork[i++], NULL) != 0)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	if (pthread_mutex_init(&g_data->msg, NULL) != 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}
