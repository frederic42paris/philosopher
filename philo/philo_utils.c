/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:42:40 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/17 18:07:18 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	if (length == 0)
		return (0);
	i = 0;
	while (first[i] != '\0' && second[i] != '\0'
		&& i < length -1 && first[i] == second[i])
	{
		i++;
	}
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

void	red(void)
{
	printf("\033[1;31m");
}

void	reset(void)
{
	printf("\033[0m");
}

void	free_struct(t_table *table)
{
	if (table->fork_lock != NULL)
		free(table->fork_lock);
	if (table->last_meal_mutex != NULL)
		free(table->last_meal_mutex);
	if (table->is_full_mutex != NULL)
		free(table->is_full_mutex);
	if (table->philo != NULL)
		free(table->philo);
	if (table->nb_meals_mutex != NULL)
		free(table->nb_meals_mutex);
	if (table != NULL)
		free(table);
}

// void	display_array(char **array)
// {
// 	int			i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// }
