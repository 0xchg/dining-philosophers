/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:03:30 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/02 18:31:58 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			id;
	int			n_meals;
	long		t_last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t	thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int		n_philo;
	int		n_philo_must_eat;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	pthread_mutex_t	*fork;
	t_philo	*philo;

}	t_data;

#endif