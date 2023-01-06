/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:25:10 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/16 18:32:54 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&philo->data->msg);
	printf("%lld philo %d take the right fork\n",
		get_milisec(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->data->msg);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&philo->data->msg);
	printf("%lld philo %d take the left fork\n",
		get_milisec(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->data->msg);
	pthread_mutex_lock(&philo->data->msg);
	printf("%lld philo %d is eating\n",
		get_milisec(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->data->msg);
	philo->last_eat = timestamp();
	ft_usleep(philo->data->time_eat);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	ft_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	printf("%lld philo %d is sleep\n",
		get_milisec(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->data->msg);
	ft_usleep(philo->data->time_sleep);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	printf("%lld philo %d is thinking\n",
		get_milisec(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->data->msg);
}
