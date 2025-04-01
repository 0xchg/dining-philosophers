/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:28:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 20:33:58 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	while(!simulation_finished(philo->data))
	{
		
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = -1;
	if (data->n_must_eat == 0)
		return ;
	else if (data->n_philo == 1)
		;
	else
	{
		while (++i < data->n_philo)
			safe_thread_handle(&data->philos[i].thread, dinner_simulation,
				&data->philos[i], T_CREATE);
	}
	data->start_simulation = ft_get_time();
	set_bool(&data->table_mutex, &data->all_t_sync, true);
	i = -1;
	while (++i < data->n_philo)
		safe_thread_handle(&data->philos[i].thread, NULL, NULL, T_JOIN);
}
