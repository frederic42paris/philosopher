/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:06:42 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/03 12:04:41 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	check_death_philo(t_philo *philo)
{
	int	temp;

	temp = 0;
	pthread_mutex_lock(&philo->table->dead_lock);
	temp = philo->table->philo_dead;
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (temp);
}

int	check_full_philo(t_philo *philo)
{
	int	temp;

	temp = 0;
	if (philo->table->full_number_set == 0)
		return (0);
	pthread_mutex_lock(&philo->table->full_lock);
	temp = philo->table->philo_full;
	pthread_mutex_unlock(&philo->table->full_lock);
	if (temp == 1)
		return (1);
	return (0);
}

int	check_death_table(t_table *table)
{
	int	temp;

	temp = 0;
	pthread_mutex_lock(&table->dead_lock);
	temp = table->philo_dead;
	pthread_mutex_unlock(&table->dead_lock);
	return (temp);
}

int	check_full_table(t_table *table)
{
	int	temp;

	temp = 0;
	if (table->full_number_set == 0)
		return (0);
	pthread_mutex_lock(&table->full_lock);
	temp = table->philo_full;
	pthread_mutex_unlock(&table->full_lock);
	if (temp == 1)
		return (1);
	return (0);
}
