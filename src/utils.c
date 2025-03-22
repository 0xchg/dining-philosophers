/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:19:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/22 05:54:38 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_msg(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}