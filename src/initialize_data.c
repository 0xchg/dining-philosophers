/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:31:12 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/01 18:26:12 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	assign_forks(t_philo *philo, t_fork	*forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->data->n_philo;
	philo->r_fork = &forks[(philo_nbr + 1) % philo_nbr];
	philo->l_fork = &forks[philo_nbr];
	if (philo->id % 2)
	{
		philo->r_fork = &forks[philo_nbr];
		philo->l_fork = &forks[(philo_nbr + 1) % philo_nbr];
	}
}

static void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->n_philo)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->n_meals = 0;
		philo->data = data;
		assign_forks(philo, data->forks, i);
		i++;
	}
}

void	initialize_data(t_data *data)
{
	int	i;

	i = 0;
	data->end_simulation = false;
	data->all_t_sync = false;
	data->philos = ft_safe_malloc(sizeof(t_philo) * data->n_philo);
	safe_mutex_handle(&data->table_mutex, M_INIT);
	data->forks = ft_safe_malloc(sizeof(t_fork) * data->n_philo);
	while (i < data->n_philo)
	{
		safe_mutex_handle(&data->forks[i].fork, M_INIT);
		data->forks[i].fork_id = i;
		i++;
	}
	philo_init(data);
}
