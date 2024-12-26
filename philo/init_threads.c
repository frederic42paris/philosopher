/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:09:07 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/03 12:43:20 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	create_threads(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->number_philo)
	{
		if (pthread_create(&(table->philo[i].tid_philo),
				NULL, routine_philo, &table->philo[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&table->tid_dead, NULL, routine_monitor, table) != 0)
		return (1);
	return (0);
}

int	join_threads(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->number_philo)
	{
		if (pthread_join(table->philo[i].tid_philo, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(table->tid_dead, NULL) != 0)
		return (1);
	return (0);
}
