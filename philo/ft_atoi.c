/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:04:39 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/16 20:13:37 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	is_n_nbr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	nb;

	i = 0;
	s = 1;
	nb = 0;
	if (is_n_nbr(str) == -1)
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (nb > 2147483647)
		{
			return (-1);
		}
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return ((int )(nb * s));
}
