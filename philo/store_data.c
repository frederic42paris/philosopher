/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:11:51 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/17 19:13:07 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	malloc_arrays(t_table *table)
{
	table->fork_lock = malloc(sizeof(pthread_mutex_t)
			* (table->number_philo + 1));
	if (table->fork_lock == NULL)
		return (1);
	memset(table->fork_lock, 0, table->number_philo + 1);
	table->last_meal_mutex = malloc(sizeof(pthread_mutex_t)
			* (table->number_philo + 1));
	if (table->last_meal_mutex == NULL)
		return (1);
	memset(table->last_meal_mutex, 0, table->number_philo + 1);
	table->is_full_mutex = malloc(sizeof(pthread_mutex_t)
			* (table->number_philo + 1));
	if (table->is_full_mutex == NULL)
		return (1);
	memset(table->is_full_mutex, 0, table->number_philo + 1);
	table->nb_meals_mutex = malloc(sizeof(pthread_mutex_t)
			* (table->number_philo + 1));
	if (table->nb_meals_mutex == NULL)
		return (1);
	memset(table->nb_meals_mutex, 0, table->number_philo + 1);
	table->philo = malloc(sizeof(t_philo) * (table->number_philo + 1));
	if (table->philo == NULL)
		return (1);
	memset(table->philo, 0, table->number_philo + 1);
	return (0);
}

void	table_data(t_table *table, int argc, char **argv)
{
	if (argc == 5)
		table->full_number_set = 0;
	else
	{
		table->full_number_set = 1;
		table->number_meals_full = ft_atoi(argv[5]);
	}
	table->number_philo = ft_atoi(argv[1]);
	table->philo_dead = 0;
	table->philo_full = 0;
	table->time_die = ft_atoi(argv[2]);
}

void	set_forks(t_table *table, int i)
{
	if (i == table->number_philo - 1)
	{
		table->philo[i].left = (i + 1) % table->number_philo;
		table->philo[i].right = i;
	}
	else
	{
		table->philo[i].left = i;
		table->philo[i].right = (i + 1) % table->number_philo;
	}
}

void	set_start(t_table *table, int i)
{
	if (table->number_philo % 2 == 1)
	{
		if (i == 0)
			table->philo[i].start = 0;
		else if (i % 2 == 1)
			table->philo[i].start = 2;
		else if (i % 2 == 0)
			table->philo[i].start = 1;
	}
	else
	{
		if (i % 2 == 0)
			table->philo[i].start = 0;
		else
			table->philo[i].start = 1;
	}
}

void	philo_data(t_table *table, char **argv)
{
	int	i;

	i = 0;
	table->start_time = get_current_time();
	while (i < table->number_philo)
	{
		set_forks(table, i);
		set_start(table, i);
		table->philo[i].number_meals = 0;
		table->philo[i].id = i + 1;
		table->philo[i].time_eat = ft_atoi(argv[3]);
		table->philo[i].time_sleep = ft_atoi(argv[4]);
		table->philo[i].table = table;
		table->philo[i].last_meal_start = table->start_time;
		table->philo[i].is_full = 0;
		if (table->number_philo % 2 == 1)
			table->philo[i].time_think = table->philo[i].time_eat * 2
				- table->philo[i].time_sleep;
		else
			table->philo[i].time_think = table->philo[i].time_eat
				- table->philo[i].time_sleep;
		if (table->philo[i].time_think < 0)
			table->philo[i].time_think = 0;
		i++;
	}
}
