/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:28:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 14:52:11 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// wait_threads(0);
	
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	if (data->n_must_eat == 0)
		return ;
	else if (data->n_philo == 1)
		;
	else
	{
		while (i < data->n_philo)
		{
			safe_thread_handle(&data->philos[i].thread, dinner_simulation,
				&data->philos[i], T_CREATE);
			i++;
		}
	}
}