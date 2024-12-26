/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:01:30 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/03 12:35:32 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	initialize_mutex(t_table *table)
{
	int		i;

	if (pthread_mutex_init(&(table->dead_lock), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(table->printf_lock), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(table->full_lock), NULL) != 0)
		return (1);
	i = 0;
	while (i < table->number_philo)
	{
		if (pthread_mutex_init(&(table->fork_lock[i]), NULL) != 0)
			return (1);
		if (pthread_mutex_init(&(table->last_meal_mutex[i]), NULL) != 0)
			return (1);
		if (pthread_mutex_init(&(table->is_full_mutex[i]), NULL) != 0)
			return (1);
		if (pthread_mutex_init(&(table->nb_meals_mutex[i]), NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	destroy_mutex(t_table *table)
{
	int		i;

	if (pthread_mutex_destroy(&(table->dead_lock)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(table->printf_lock)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(table->full_lock)) != 0)
		return (1);
	i = 0;
	while (i < table->number_philo)
	{
		if (pthread_mutex_destroy(&(table->fork_lock[i])) != 0)
			return (1);
		if (pthread_mutex_destroy(&(table->last_meal_mutex[i])) != 0)
			return (1);
		if (pthread_mutex_destroy(&(table->is_full_mutex[i])) != 0)
			return (1);
		if (pthread_mutex_destroy(&(table->nb_meals_mutex[i])) != 0)
			return (1);
		i++;
	}
	return (0);
}
