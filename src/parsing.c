/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:25:36 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/22 05:43:50 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
long	ft_atol(const char *str)
{
	long	number;

	number = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '+')
			str++;
		else
			error_msg("Can't take negative values");
	}
	if (ft_strlen(str) > 10)
		error_msg("Values too big!");
	while (ft_isdigit(*str))
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	if (number > INT_MAX)
		error_msg("Values too big!");
	return (number);
}

void	parse_input(t_table *table, char **av)
{
	table->nbr_of_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1000;
	table->time_to_eat = ft_atol(av[3]) * 1000;
	table->time_to_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		table->nbr_philo_must_eat = ft_atol(av[5]);
	else
		table->nbr_philo_must_eat = -1;


}

