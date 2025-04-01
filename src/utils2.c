/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:51:55 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 22:15:55 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo, long elapsed)
{
	if (status == TAKE_FIRST_FORK && !simulation_finished(philo->data))	
		printf("%ld %d has taken the first fork\n", elapsed, philo->id);
	else if (status == TAKE_SECOND_FORK && !simulation_finished(philo->data))	
		printf("%ld %d has taken the second fork\n", elapsed, philo->id);
	else if (status == EATING && !simulation_finished(philo->data))	
		printf("%ld %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->data))	
		printf("%ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(philo->data))	
		printf("%ld %d is thinking\n", elapsed, philo->id);
	else if (status == DIED && !simulation_finished(philo->data))	
		printf("%ld %d died!\n", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = ft_get_time() - philo->data->start_simulation;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->data->write_mutex, M_LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			&& !simulation_finished(philo->data))	
			printf("%ld %d has taken a fork\n", elapsed, philo->id);
		else if (status == EATING && !simulation_finished(philo->data))	
			printf("%ld %d is eating\n", elapsed, philo->id);
		else if (status == SLEEPING && !simulation_finished(philo->data))	
			printf("%ld %d is sleeping\n", elapsed, philo->id);
		else if (status == THINKING && !simulation_finished(philo->data))	
			printf("%ld %d is thinking\n", elapsed, philo->id);
		else if (status == DIED && !simulation_finished(philo->data))	
			printf("%ld %d died!\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->data->write_mutex, M_UNLOCK);
}
