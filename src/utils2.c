/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:51:55 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/06 13:07:46 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	error_msg(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

void	set_long(t_mutex *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(t_mutex *mutex, long *src)
{
	long	ret;

	pthread_mutex_lock(mutex);
	ret = *src;
	pthread_mutex_unlock(mutex);
	return (ret);
}
