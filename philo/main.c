/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:41:43 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/17 18:20:02 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	parse_input(char *string)
{
	int		int_from_str;
	char	*str_from_int;

	int_from_str = ft_atoi(string);
	str_from_int = ft_itoa(int_from_str);
	if (!str_from_int)
		return (free(str_from_int), -1);
	if (ft_strncmp(string, str_from_int, ft_strlen(string)))
		return (free(str_from_int), -1);
	if (!int_from_str)
		return (free(str_from_int), -1);
	return (free(str_from_int), int_from_str);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	while (i < argc)
	{
		if (parse_input(argv[i]) <= 0)
		{
			printf("Negative or equal to 0\n");
			return (1);
		}
		i++;
	}
	return (0);
}

long	get_current_time(void)
{
	struct timeval	current;
	long			current_ms;

	gettimeofday(&current, NULL);
	current_ms = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (current_ms);
}

int	main(int argc, char **argv)
{
	t_table			*table;

	if (check_arguments(argc, argv) == 1)
		return (1);
	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (free(table), 1);
	table_data(table, argc, argv);
	if (malloc_arrays(table) == 1)
		return (free_struct(table), 1);
	philo_data(table, argv);
	if (initialize_mutex(table) == 1)
		return (free_struct(table), destroy_mutex(table), 1);
	create_threads(table);
	join_threads(table);
	destroy_mutex(table);
	free_struct(table);
	return (0);
}
