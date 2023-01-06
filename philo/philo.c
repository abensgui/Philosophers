/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:41:31 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/17 17:42:09 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	*routine(void *s)
{
	t_philo	*philo;

	philo = (t_philo *)s;
	while (1)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
		usleep(50);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_global	*g_data;

	if (check_arg(ac, av) != -1 && (ac == 5 || ac == 6))
	{
		if (av[5] && ft_atoi(av[5]) == 0)
			return (0);
		philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		g_data = malloc(sizeof(t_global));
		g_data->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
		if (!g_data->fork || !philo || !g_data)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (mutex_init(g_data, ft_atoi(av[1])) == -1)
			return (0);
		create_gdata(g_data, ac, av);
		if (create_data(g_data, philo, av, &routine) == -1)
			return (0);
		check_die(philo);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
