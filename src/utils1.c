/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:35:02 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 19:21:18 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_destroy_mutex_fork(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		pthread_mutex_destroy(&data->fork[i]);
}

void	ft_destroy_free(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->print);
	while (++i < data->n_philo)
		pthread_mutex_destroy(&data->fork[i]);
	free (data->fork);
	free (data->philo);
}

static int table_util(t_philo *root)
{
	long	elapsed;

	elapsed = ft_get_time() - get_long(&root->data->data_mutex, &root->t_last_meal);
	if (elapsed > (root->data->time_to_die / 1000))
	{
		print_status(root, "died");
		set_bool(&root->data->data_mutex, &root->data->table.died, true);
		return (1);
	}
	if ((root->n_meals >= root->data->n_philo_must_eat)
		&& root->data->n_philo_must_eat != -1)
		root->data->table.n_meals++;
	if (root->data->table.n_meals == root->data->n_philo)
	{
		print_status(root, "All philosophers ate");
		set_bool(&root->data->data_mutex, &root->data->table.all_ate, true);
		return (1);
	}
	return (0);
}

void	table(t_data *data)
{
	int	i;
	t_philo *root;

	while(1)
	{
		i = -1;
		data->table.n_meals = false;
		while (++i < data->n_philo)
		{
			root = &data->philo[i];
			if (table_util(root))
				return ;
		}
	}
}
