/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:35:02 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 18:10:06 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	safe_mutex_handle(mutex, M_LOCK);
	*dest = value;
	safe_mutex_handle(mutex, M_UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	ret;
	
	safe_mutex_handle(mutex, M_LOCK);
	ret = *value;
	safe_mutex_handle(mutex, M_UNLOCK);
	return	(ret);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	ret;
	
	safe_mutex_handle(mutex, M_LOCK);
	ret = *value;
	safe_mutex_handle(mutex, M_UNLOCK);
	return	(ret);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex_handle(mutex, M_LOCK);
	*dest = value;
	safe_mutex_handle(mutex, M_UNLOCK);
}

bool	simulation_finished(t_data *data)
{
	return (get_bool(&data->table_mutex, &data->end_simulation));
}