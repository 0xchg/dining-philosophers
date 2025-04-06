/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:27:23 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/06 15:05:43 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_bool(t_mutex *data_mutex, bool *dest, bool value)
{
	pthread_mutex_lock(data_mutex);
	*dest = value;
	pthread_mutex_unlock(data_mutex);
}

bool	get_bool(t_mutex *data_mutex, bool *src)
{
	bool	ret;

	pthread_mutex_lock(data_mutex);
	ret = *src;
	pthread_mutex_unlock(data_mutex);
	return (ret);
}

void	inc_long(t_mutex *data_mutex, long *dest)
{
	pthread_mutex_lock(data_mutex);
	(*dest)++;
	pthread_mutex_unlock(data_mutex);
}

int	dinner_checker(t_philo *philo)
{
	if ((get_long(&philo->data->data_mutex, &philo->n_meals)
			== philo->data->n_philo_must_eat)
		|| (get_bool(&philo->data->data_mutex, &philo->data->table.died)
			|| get_bool(&philo->data->data_mutex, &philo->data->table.all_ate)))
		return (1);
	return (0);
}
