/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:25:36 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 13:43:45 by mchingi          ###   ########.fr       */
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
			return(error_msg("Can't take negative values\n"));
	}
	if (ft_strlen(str) > 10)
		return(error_msg("Values too big!\n"));
	while (ft_isdigit(*str))
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	if (number > INT_MAX)
		return(error_msg("Values too big!\n"));
	return (number);
}

int	parse_input(t_data *data, char **av)
{
	data->n_philo = ft_atol(av[1]);
	if (data->n_philo < 1)
		return(error_msg("Error: Number of Philosopher must be at least 1\n"));
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		data->n_philo_must_eat = ft_atol(av[5]);
	else
		data->n_philo_must_eat = -1;
	if (data->time_to_die < 60000 || data->time_to_eat < 60000 || data->time_to_sleep < 60000)
		return (error_msg("Timestamp can not be < 60ms\n"));
	return (1);
}
