/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:19:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 20:50:33 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_msg(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

void	*ft_safe_malloc(size_t bytes)
{
	void	*return_pointer;

	return_pointer = malloc(bytes);
	if (!return_pointer)
		error_msg("Something wrong with malloc!\n");
	return (return_pointer);
}

long	ft_get_time(void)
{
	long			time_ms;
	struct timeval 	time;

	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_ms);
}

void	ft_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = ft_get_time();
	while (ft_get_time() - start < usec)
	{
		if (simulation_finished(data))
			break ;
		elapsed = ft_get_time() - start;
		remaining = usec - elapsed;
		if (remaining > 1e3)
			usleep(usec / 2);
		else
		{
			while (ft_get_time() - start < usec)
				;
		}
	}
}
