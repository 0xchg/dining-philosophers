/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:14:44 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/10 19:41:44 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ft_input_validation(&data, av) < 0)
			return (0);
		if (ft_initialize_print(&data) < 0 || ft_initialize_fork(&data) < 0)
			return (0);
		if (ft_initialize_philo(&data) < 0)
			return (0);
		if (ft_start_simulation(&data) < 0)
			return (0);
		ft_destroy_free(&data);
		return (0);
	}
	else
		error_msg("Error: wrong number of args. Ex.: 5 800 200 200 [5]\n");
	return (0);
}
