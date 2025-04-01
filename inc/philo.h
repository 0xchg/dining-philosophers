/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:03:30 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 15:30:18 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>

typedef struct s_data	t_data;

typedef enum e_type
{
	M_INIT,
	M_LOCK,
	M_UNLOCK,
	M_DESTROY,
	T_CREATE,
	T_DETACH,
	T_JOIN
}		t_type;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}					t_fork;

typedef struct s_philo
{
	int			id;
	long		n_meals;
	bool 		full;
	long		t_last_meal;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread;
	t_data		*data;
}				t_philo;

typedef struct s_data
{
	long	n_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	n_must_eat;
	long	start_simulation;
	bool	end_simulation;
	bool	all_t_sync;
	pthread_mutex_t	table_mutex;
	t_fork	*forks;
	t_philo	*philos;
}		t_data;

void	safe_mutex_handle(pthread_mutex_t *mutex, t_type mutex_type);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_type thread_type);
void	parse_input(t_data *data, char **av);
void	initialize_data(t_data *data);

void	error_msg(char *str);
void	*safe_malloc(size_t bytes);
int		ft_strlen(const char *str);

#endif