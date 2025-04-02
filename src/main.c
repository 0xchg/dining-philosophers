/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:14:44 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/02 17:51:29 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		parse_input(data, av);
		initialize_data(data);
		start_simulation(data);
		free(data);
	}
	else
		error_msg("Error: wrong number of args. Ex.: 5 800 200 200 [5]");
	return (0);
}
