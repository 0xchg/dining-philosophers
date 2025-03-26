/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 04:18:11 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/26 14:54:47 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	handle_mutex_error(int status, t_type mutex_type)
{
	if (status == 0)
		return ;
	else if (status == EINVAL && (mutex_type == M_LOCK
		|| mutex_type == M_UNLOCK))
		error_msg("The value specified by mutex is invalid.\n");
	else if (status == EINVAL && mutex_type == M_INIT)
		error_msg("The value specified by attr is invalid.\n");
	else if (status == EDEADLK)
		error_msg("A dead lock would occur if the thread blocked waiting for mutex\n");
	else if (status == EBUSY)
		error_msg("");
	else if (status == )
		;
}

void	mutex_handler(t_mtx *mutex, t_type mutex_type)
{
	if (M_INIT == mutex_type)
		pthread_mutex_init(mutex, NULL);
	else if (M_LOCK == mutex_type)
		pthread_mutex_lock(mutex);
	else if (M_UNLOCK == mutex_type)
		pthread_mutex_unlock(mutex);
	else if (M_DESTROY == mutex_type)
		pthread_mutex_destroy(mutex);
	else
		error_msg("Wrong mutex_type\n");
}