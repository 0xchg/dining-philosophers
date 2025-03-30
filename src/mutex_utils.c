/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 04:18:11 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/30 20:48:41 by mchingi          ###   ########.fr       */
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
		error_msg("A dead lock would occur if the thread blocked waiting"
			" for mutex\n");
	else if (status == EBUSY)
		error_msg("Mutex is locked\n");
	else if (status == EPERM)
		error_msg("The current thread does not hold a lock on mutex.\n");
	else if (status == ENOMEM)
		error_msg("The process cannot allocate enough memory to"
			" create another mutex.\n");
}

void	safe_mutex_handle(t_mtx *mutex, t_type mutex_type)
{
	if (M_INIT == mutex_type)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), mutex_type);
	else if (M_LOCK == mutex_type)
		handle_mutex_error(pthread_mutex_lock(mutex), mutex_type);
	else if (M_UNLOCK == mutex_type)
		handle_mutex_error(pthread_mutex_unlock(mutex), mutex_type);
	else if (M_DESTROY == mutex_type)
		handle_mutex_error(pthread_mutex_destroy(mutex), mutex_type);
	else
		error_msg("Wrong mutex_type\n");
}
