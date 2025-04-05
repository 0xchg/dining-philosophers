/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:19:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 19:14:20 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_safe_mutex_init(mutex_t *mutex, int i, mutex_t *print_mutex)
{
	int	j;

	j = -1;
	if (pthread_mutex_init(&mutex[i], NULL))
	{
		pthread_mutex_destroy(print_mutex);
		while (++j < i)
			pthread_mutex_destroy(&mutex[j]);
		return (-1);
	}
	return (0);
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

void	print_status(t_philo *root, char *str)
{
	long	time_ms;

	time_ms = (ft_get_time() - root->data->init_time);
	pthread_mutex_lock(&root->data->print);
	if (get_bool(&root->data->data_mutex, &root->data->table.all_ate) || get_bool(&root->data->data_mutex, &root->data->table.died))
	{
		pthread_mutex_unlock(&root->data->print);
		return ;
	}
	printf("%ld %d %s\n", time_ms, root->id, str);
	pthread_mutex_unlock(&root->data->print);
}
