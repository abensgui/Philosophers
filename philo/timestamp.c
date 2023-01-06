/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:58:28 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/16 20:16:17 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	long long		milsec;
	struct timeval	te;

	gettimeofday(&te, NULL);
	milsec = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milsec);
}

long long	get_milisec(t_philo *philo)
{
	return (timestamp() - philo->start_time);
}
