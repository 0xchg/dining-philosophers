/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:31:12 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 18:27:05 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_initialize_print(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL))
		return (error_msg("Error: Mutex (print) initialization fails\n"));
	if (pthread_mutex_init(&data->data_mutex, NULL))
		return (error_msg("Error: Mutex (data_mutex) initialization fails\n"));
	return (1);
}

int	ft_initialize_fork(t_data *data)
{
	int	i;

	data->fork = ft_safe_malloc(sizeof(pthread_mutex_t) * data->n_philo);
	i = -1;
	while (++i < data->n_philo)
	{
		if (ft_safe_mutex_init(data->fork, i, &data->print))
		{
			free (data->fork);
			return (error_msg("Error: Mutex (fork) initialization fails\n"));
		}
	}
	return (1);
}

int	ft_initialize_philo(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
	{
		pthread_mutex_destroy(&data->print);
		ft_destroy_mutex_fork(data);
		free (data->fork);
		return (error_msg("Malloc data->philosophers fails\n"));
	}
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i].id = i +1;
		data->philo[i].n_meals = 0;
		data->philo[i].left_fork = &data->fork[i];
		data->philo[i].right_fork = &data->fork[(i + 1) % data->n_philo];
		data->philo[i].data = data;
	}
	return (1);
}
