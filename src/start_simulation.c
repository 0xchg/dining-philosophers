/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:28:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/02 17:49:13 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	ft_thinking(t_philo *philo)
{
	write_status(THINKING, philo, 0);
}

static void ft_eat(t_philo *philo)
{
	safe_mutex_handle(&philo->r_fork->fork, M_LOCK);
	write_status(TAKE_RIGHT_FORK, philo, 0);
	safe_mutex_handle(&philo->l_fork->fork, M_LOCK);
	write_status(TAKE_LEFT_FORK, philo, 0);
	set_long(&philo->philo_mutex, &philo->t_last_meal, ft_get_time());
	philo->n_meals++;
	write_status(EATING, philo, 0);
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->n_must_eat > 0 
		&& philo->n_meals == philo->data->n_must_eat)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex_handle(&philo->r_fork->fork, M_UNLOCK);
	safe_mutex_handle(&philo->l_fork->fork, M_UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	while(!simulation_finished(philo->data))
	{
		if (philo->full)
			break ;
		ft_eat(philo);
		write_status(SLEEPING, philo, 0);
		ft_usleep(philo->data->time_to_sleep, philo->data);
		ft_thinking(philo);
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
