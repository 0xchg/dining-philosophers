/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:27:23 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 18:47:37 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_bool(mutex_t *data_mutex, bool *dest, bool value)
{
	pthread_mutex_lock(data_mutex);
	*dest = value;
	pthread_mutex_unlock(data_mutex);
}

bool	get_bool(mutex_t *data_mutex, bool *src)
{
	bool	ret;

	pthread_mutex_lock(data_mutex);
	ret = *src;
	pthread_mutex_unlock(data_mutex);
	return (ret);
}