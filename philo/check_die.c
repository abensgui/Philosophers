/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:45:46 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/17 17:28:50 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_die(t_philo *philo)
{
	if (philo->data->nb_philo_eat == philo->data->nb_philo
		&& philo->data->nb_must_eat)
		return (1);
	if (timestamp() - philo->last_eat >= philo->data->time_die)
	{
		pthread_mutex_lock(&philo->data->msg);
		printf("%lld philo %d is die\n", get_milisec(philo), philo->id + 1);
		return (1);
	}
	return (0);
}

void	check_die(t_philo *philo)
{
	int	die;
	int	i;

	die = 0;
	while (die == 0)
	{
		i = 0;
		while (i < philo->data->nb_philo)
		{
			if (philo[i].nb_eat == philo[i].data->nb_must_eat
				&& philo[i].fin_nb_eat == 0)
			{
				philo[i].data->nb_philo_eat++;
				philo[i].fin_nb_eat = 1;
			}
			if (ft_die(&philo[i]) == 1)
			{
				die = 1;
				break ;
			}
			i++;
		}
	}
}
