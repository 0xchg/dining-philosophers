/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:14:44 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/30 20:50:28 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	// t_table	*philo;

	// philo = malloc(sizeof(t_table));
	if (ac == 5 || ac == 6)
	{
		// parse_input(philo, av);
		
		// free(philo);
	}
	else
		error_msg("Error: wrong number of args. Ex.: 5 800 200 200 [5]");
	return (0);
}
