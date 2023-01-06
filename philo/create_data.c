/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:43:53 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/17 17:51:59 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_gdata(t_global *g_data, int ac, char **av)
{
	g_data->nb_philo = ft_atoi(av[1]);
	g_data->time_die = ft_atoi(av[2]);
	g_data->time_eat = ft_atoi(av[3]);
	g_data->time_sleep = ft_atoi(av[4]);
	g_data->nb_philo_eat = 0;
	g_data->die = 0;
	if (ac == 6)
		g_data->nb_must_eat = ft_atoi(av[5]);
}

int	create_data(t_global *g_data, t_philo *philo, char **av, void *routine)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].data = g_data;
		philo[i].id = i;
		philo[i].start_time = timestamp();
		philo[i].right = &g_data->fork[i];
		philo[i].left = &g_data->fork[(i + 1) % ft_atoi(av[1])];
		philo[i].last_eat = timestamp();
		philo[i].nb_eat = 0;
		philo[i].fin_nb_eat = 0;
		if (pthread_create(&philo[i].t, NULL, routine, &philo[i]) != 0)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
		usleep (50);
	}
	return (1);
}
