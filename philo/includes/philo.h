/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:14:24 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/17 19:12:42 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				time_eat;
	int				time_sleep;
	int				left;	
	int				right;
	pthread_t		tid_philo;
	long			last_meal_start;
	int				is_full;
	int				start;
	int				time_think;
	int				number_meals;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				number_philo;
	int				time_die;
	int				number_meals_full;
	int				full_number_set;
	long			start_time;
	pthread_t		tid_dead;
	pthread_t		tid_full;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	full_lock;
	pthread_mutex_t	start_lock;
	int				philo_dead;
	int				philo_full;
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	*last_meal_mutex;
	pthread_mutex_t	*is_full_mutex;
	pthread_mutex_t	*nb_meals_mutex;
	pthread_mutex_t	printf_lock;
	t_philo			*philo;
}	t_table;

// check arguments
int		check_arguments(int argc, char **argv);

// store data
void	philo_data(t_table *table, char **argv);
void	table_data(t_table *table, int argc, char **argv);
int		malloc_arrays(t_table *table);

// Initialize threads and mutex
int		initialize_mutex(t_table *table);
int		destroy_mutex(t_table *table);
int		create_threads(t_table *table);
int		join_threads(t_table *table);

// Philo actions
int		philo_fork(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_eat(t_philo *philo);

// routine_philo
void	*routine_philo(void *data);

// routine_table
void	*routine_monitor(void *data);

// Check data that needs mutex
int		check_death_philo(t_philo *philo);
int		check_full_philo(t_philo *philo);
int		check_death_table(t_table *table);
int		check_full_table(t_table *table);

// get_time
long	get_current_time(void);

// Utils
long	ft_atoi(const char *string);
void	red(void);
void	reset(void);
void	free_struct(t_table *table);
size_t	ft_strlen(const char *string);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_itoa(int num);
long	ft_atoi(const char *string);
// void	display_array(char **argv);

#endif