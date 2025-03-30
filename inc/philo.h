/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:03:30 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/30 20:37:59 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# include <errno.h>
# include <limits.h>

typedef struct s_table	t_table;

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
	long		meals_counter;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long	nbr_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_philo_must_eat;
	long	start_simulation;
	t_fork	*forks;
	t_philo	*philos;
}		t_table;

void	safe_mutex_handle(t_mtx *mutex, t_type mutex_type);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_type thread_type);
void	parse_input(t_table *table, char **av);

void	error_msg(char *str);
void	*safe_malloc(size_t bytes);
int		ft_strlen(const char *str);

#endif