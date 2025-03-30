/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:01:23 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/30 20:39:34 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	handle_thread_error(int status, t_type thread_type)
{
	if (status == 0)
		return ;
	else if (status == EAGAIN)
		error_msg("Insufficient resources to create another thread.\n");
	else if (status == EINVAL && thread_type == T_CREATE)
		error_msg("The value specified by attr is invalid\n");
	else if (status == EPERM)
		error_msg("The caller does not have appropriate permission\n");
	else if (status == EDEADLK)
		error_msg("A  deadlock  was  detected\n");
	else if (status == EINVAL && thread_type == T_JOIN)
		error_msg("thread is not a joinable thread.\n");
	else if (status == ESRCH)
		error_msg("No thread with the ID thread could be found.\n");
}

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
		t_type thread_type)
{
	if (thread_type == T_CREATE)
		handle_thread_error(pthread_create(thread, NULL, foo, data),
			thread_type);
	else if (thread_type == T_JOIN)
		handle_thread_error(pthread_join(*thread, NULL), thread_type);
	else if (thread_type == T_DETACH)
		handle_thread_error(pthread_detach(*thread), thread_type);
	else
		error_msg("Wrong call from thread_handle\n");
}
