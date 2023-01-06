/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:48:41 by abensgui          #+#    #+#             */
/*   Updated: 2022/04/17 02:55:06 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct t_global
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_must_eat;
	int				nb_philo_eat;
	int				die;
}	t_global;

typedef struct s_philo
{
	t_global		*data;
	int				id;
	int				nb_eat;
	int				fin_nb_eat;
	long long		start_time;
	pthread_t		t;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long long		last_eat;
}	t_philo;

int			ft_atoi(const char *str);
long long	timestamp(void);
void		ft_usleep(int time);
long long	get_milisec(t_philo *philo);
void		check_die(t_philo *philo);
int			create_data(t_global *g_data, t_philo *philo,
				char **av, void *routine);
void		create_gdata(t_global *g_data, int ac, char **av);
int			mutex_init(t_global *g_data, int c);
void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
#endif