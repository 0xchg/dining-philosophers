/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:03:30 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/05 19:23:03 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h> 

typedef pthread_mutex_t mutex_t ;

typedef struct s_table
{
	bool	all_ate;
	bool	died;
	long	n_meals;
}	t_table;

typedef struct s_philo
{
	int			id;
	long			n_meals;
	long		t_last_meal;
	mutex_t		*right_fork;
	mutex_t		*left_fork;
	pthread_t	thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	bool		all_threads_sync;
	int			n_philo;
	int			n_philo_must_eat;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		init_time;
	mutex_t		*fork;
	mutex_t		data_mutex;
	mutex_t		print;
	t_philo		*philo;
	t_table		table;
}	t_data;

void	ft_destroy_mutex_fork(t_data *data);
void	ft_destroy_free(t_data *data);
int		ft_initialize_print(t_data *data);
int		ft_initialize_fork(t_data *data);
int		ft_initialize_philo(t_data *data);
int		ft_start_simulation(t_data *data);

// ---------------------- PARSING ----------------------/
int		parse_input(t_data *data, char **av);

// ---------------------- UTILS ------------------------/
void	*ft_safe_malloc(size_t bytes);
void	print_status(t_philo *root, char *str);
void	table(t_data *data);
void	set_long(mutex_t *data_mutex, long *dest, long value);
long	get_long(mutex_t *data_mutex, long *src);
void	set_bool(mutex_t *data_mutex, bool *dest, bool value);
bool	get_bool(mutex_t *data_mutex, bool *src);
int		error_msg(char *str);
int		ft_safe_mutex_init(mutex_t *mutex, int i, mutex_t *print_mutex);
long	ft_get_time(void);
size_t	ft_strlen(const char *str);

#endif