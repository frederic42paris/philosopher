/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:22:05 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/03 12:04:41 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	philo_fork(t_philo *philo)
{
	long			current_ms;

	if (check_death_philo(philo) != 0 || check_full_philo(philo) != 0)
		return (1);
	current_ms = get_current_time();
	pthread_mutex_lock(&(philo->table->printf_lock));
	printf("%ld %d %s\n", current_ms - philo->table->start_time, philo->id,
		"has taken a fork");
	pthread_mutex_unlock(&(philo->table->printf_lock));
	return (0);
}

int	philo_think(t_philo *philo)
{
	long			current_ms;

	if (check_death_philo(philo) != 0 || check_full_philo(philo) != 0)
		return (1);
	current_ms = get_current_time();
	pthread_mutex_lock(&(philo->table->printf_lock));
	printf("%ld %d %s\n", current_ms - philo->table->start_time, philo->id,
		"is thinking");
	pthread_mutex_unlock(&(philo->table->printf_lock));
	usleep(philo->time_think * 1000);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	long			current_ms;

	usleep(10);
	if (check_death_philo(philo) != 0 || check_full_philo(philo) != 0)
		return (1);
	current_ms = get_current_time();
	pthread_mutex_lock(&(philo->table->printf_lock));
	printf("%ld %d %s\n", current_ms - philo->table->start_time, philo->id,
		"is sleeping");
	pthread_mutex_unlock(&(philo->table->printf_lock));
	usleep(philo->time_sleep * 1000);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	long			current_ms;

	if (check_death_philo(philo) != 0 || check_full_philo(philo) != 0)
		return (1);
	current_ms = get_current_time();
	pthread_mutex_lock(&philo->table->last_meal_mutex[philo->id - 1]);
	philo->last_meal_start = current_ms;
	pthread_mutex_unlock(&philo->table->last_meal_mutex[philo->id - 1]);
	pthread_mutex_lock(&(philo->table->printf_lock));
	red();
	printf("%ld %d %s\n", current_ms - philo->table->start_time, philo->id,
		"is eating");
	reset();
	pthread_mutex_unlock(&(philo->table->printf_lock));
	usleep(philo->time_eat * 1000);
	pthread_mutex_lock(&philo->table->nb_meals_mutex[philo->id - 1]);
	philo->number_meals++;
	pthread_mutex_unlock(&philo->table->nb_meals_mutex[philo->id - 1]);
	return (0);
}

void	*routine_philo(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	usleep(philo->start * philo->time_eat * 1000);
	if (philo->table->number_philo > 1)
	{
		while (check_death_philo(philo) == 0 && check_full_philo(philo) == 0)
		{
			pthread_mutex_lock(&(philo->table->fork_lock[philo->left]));
			pthread_mutex_lock(&(philo->table->fork_lock[philo->right]));
			philo_fork(philo);
			philo_fork(philo);
			philo_eat(philo);
			pthread_mutex_unlock(&(philo->table->fork_lock[philo->left]));
			pthread_mutex_unlock(&(philo->table->fork_lock[philo->right]));
			philo_sleep(philo);
			philo_think(philo);
		}
	}
	else
		philo_fork(philo);
	return (0);
}
