/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:22:27 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/03 12:04:41 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// int	get_number_meals(t_philo *philo)
// {
// 	int	temp;

// 	temp = 0;
// 	pthread_mutex_lock(&philo->table->nb_meals_mutex[philo->id - 1]);
// 	temp = philo->number_meals;
// 	pthread_mutex_unlock(&philo->table->nb_meals_mutex[philo->id - 1]);
// 	return (temp);
// }

// void	*routine_check_full(void *data)
// {
// 	int			i;
// 	int			temp;
// 	t_table		*table;

// 	table = (t_table *)data;
// 	while (check_death_table(table) == 0 && check_full_table(table) == 0)
// 	{
// 		i = 0;
// 		temp = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (get_number_meals(&table->philo[i]) >= table->number_meals_full)
// 				table->philo[i].is_full = 1;
// 			if (table->philo[i].is_full == 1)
// 				temp++;
// 			i++;
// 		}
// 		if (temp == table->number_philo)
// 		{
// 			pthread_mutex_lock(&table->full_lock);
// 			table->philo_full = 1;
// 			pthread_mutex_unlock(&table->full_lock);
// 		}
// 		usleep(1);
// 	}
// 	return (0);
// }

// void	print_death(t_table *table, long current_ms)
// {
// 	if (table->philo_dead != 0)
// 	{
// 		pthread_mutex_lock(&(table->printf_lock));
// 		printf("%ld %d died\n",
// 			current_ms - table->start_time, table->philo_dead);
// 		pthread_mutex_unlock(&(table->printf_lock));
// 	}
// }

// int	get_last_meal(t_philo *philo, long current_ms)
// {
// 	long	temp;

// 	temp = 0;
// 	pthread_mutex_lock(&philo->table->last_meal_mutex[philo->id - 1]);
// 	temp = philo->last_meal_start;
// 	pthread_mutex_unlock(&philo->table->last_meal_mutex[philo->id - 1]);
// 	return (current_ms - temp);
// }

// void	*routine_check_dead(void *data)
// {
// 	long		current_ms;
// 	int			i;
// 	t_table		*table;

// 	table = (t_table *)data;
// 	while (check_death_table(table) == 0 && check_full_table(table) == 0)
// 	{
// 		i = 0;
// 		current_ms = get_current_time();
// 		while (i < table->number_philo)
// 		{
// 			pthread_mutex_lock(&table->dead_lock);
// 			if (get_last_meal(&table->philo[i], current_ms) >= table->time_die)
// 				table->philo_dead = table->philo[i].id;
// 			pthread_mutex_unlock(&table->dead_lock);
// 			i++;
// 		}
// 		usleep(1);
// 	}
// 	print_death(table, current_ms);
// 	return (0);
// }
