/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:28:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 19:24:57 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void ft_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep);
}

static void	ft_eat(t_philo *philo)
{
	print_status(philo, "is eating");
	set_long(&philo->data->data_mutex, &philo->t_last_meal, ft_get_time());
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->n_meals++;
}

static int	ft_grad_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (philo->data->n_philo == 1)
	{
		usleep(philo->data->time_to_eat);
		return (0);
	}
	if (get_bool(&philo->data->data_mutex, &philo->data->table.died))
		return (0);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	return (1);
}

void	*ft_diner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	set_long(&philo->data->data_mutex, &philo->t_last_meal, ft_get_time());
	while (1)
	{
		if (get_bool(&philo->data->data_mutex, &philo->data->table.died))
			break ;
		if (!ft_grad_forks(philo))
			break ;
		if (get_bool(&philo->data->data_mutex, &philo->data->table.died))
			break ;
		ft_eat(philo);
		if ((philo->n_meals == philo->data->n_philo_must_eat) 
			|| (get_bool(&philo->data->data_mutex, &philo->data->table.died)
			|| get_bool(&philo->data->data_mutex, &philo->data->table.all_ate)))
			break ;
		ft_sleep(philo);
		if (get_bool(&philo->data->data_mutex, &philo->data->table.died))
			break ;
		print_status(philo, "is thinking");
	}
	return (NULL);
}

int	ft_start_simulation(t_data *data)
{
	int	i;

	i = -1;
	set_bool(&data->data_mutex, &data->table.all_ate, false);
	set_bool(&data->data_mutex, &data->table.died, false);
	data->init_time = ft_get_time();
	while (++i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
			ft_diner_simulation, &data->philo[i]))
		{
			ft_destroy_free(data);
			return(error_msg("Error: The simulation fails\n"));
		}
		usleep(1000);
	}
	table(data);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philo[i].thread, NULL);
	return (1);
}
