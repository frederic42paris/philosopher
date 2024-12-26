/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:39:12 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/28 16:44:21 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////// BROUILLON

// long	get_current_time(void)
// {
// 	struct timeval	current;
// 	long			current_ms;

// 	gettimeofday(&current, NULL);
// 	current_ms = current.tv_sec * 1000 + current.tv_usec / 1000;
// 	return (current_ms);
// }

// void	philo_fork(t_philo *philo, int fork)
// {
// 	long			current_ms;

// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	current_ms = get_current_time();
// 	pthread_mutex_lock(&philo->table->dead_lock);
// 	printf("%ld %d %s %d\n", 
// current_ms - philo->table->start_time, philo->id, "has taken a fork", fork);
// 	pthread_mutex_unlock(&philo->table->dead_lock);
// }

// void	philo_think(t_philo *philo)
// {
// 	long			current_ms;

// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	current_ms = get_current_time();
// 	printf("%ld %d %s\n",
// current_ms - philo->table->start_time, philo->id, "is thinking");
// }

// void	philo_sleep(t_philo *philo)
// {
// 	long			current_ms;

// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	current_ms = get_current_time();
// 	printf("%ld %d %s\n",
// current_ms - philo->table->start_time, philo->id, "is sleeping");
// 	usleep(philo->time_sleep * 1000);
// }

// void	philo_eat(t_philo *philo)
// {
// 	long			current_ms;
// 	// int				temp;

// 	// pthread_mutex_lock(&philo->table->dead_lock);
// 	// temp = philo->table->philo_dead;
// 	// pthread_mutex_unlock(&philo->table->dead_lock);
// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	current_ms = get_current_time();
// 	philo->last_meal_start = get_current_time();
// 	// pthread_mutex_lock(&(philo->table->dead_lock));
// 	printf("%ld %d %s\n",
// current_ms - philo->table->start_time, philo->id, "is eating");
// 	// pthread_mutex_unlock(&(philo->table->dead_lock));
// 	usleep(philo->time_eat * 1000);
// 	pthread_mutex_lock(&(philo->table->printf_lock));
// 	philo->can_eat = 0;
// 	pthread_mutex_unlock(&(philo->table->printf_lock));
// 	// philo->number_meals++;
// 	// philo->table->counter = 1;
// 	// if (philo->number_meals >= philo->number_meals_full)
// 	// {
// 	// 	pthread_mutex_lock(&(philo->table->full_lock));
// 	// 	philo->table->philo_full = philo->id;
// 	// 	pthread_mutex_unlock(&(philo->table->full_lock));
// 	// }
// }

// void	fill_table(t_table *table, int start, int end)
// {
// 	while (start < end)
// 	{
// 		table->philo[start].can_eat = 1;
// 		start++;
// 		start++;
// 	}
// }

// void	store_data(t_table *table, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	table->number_philo = ft_atoi(argv[1]);
// 	table->philo_dead = 0;
// 	table->philo_full = 0;
// 	table->counter = 0;
// 	table->time_die = ft_atoi(argv[2]);
// 	table->number_meals_full = ft_atoi(argv[5]);
// 	table->philo = malloc(sizeof(t_philo) * (table->number_philo + 1));
// 	table->fork_mutex = malloc(sizeof(pthread_mutex_t)
	// * (table->number_philo + 1));
// 	while (i < table->number_philo)
// 	{
// 		table->philo[i].number_meals = 0;
// 		table->philo[i].id = i + 1;
// 		table->philo[i].time_eat = ft_atoi(argv[3]);
// 		table->philo[i].time_sleep = ft_atoi(argv[4]);
// 		table->philo[i].table = table;
// 		table->philo[i].last_meal_start = table->start_time;
// 		table->philo[i].can_eat = 0;
// 		i++;
// 	}
// 	if (table->number_philo % 2 == 0)
// 	{
// 		table->odd = 1;
// 		table->even = 0;
// 		table->one = 0;
// 	}
// 	else
// 	{
// 		table->odd = 0;
// 		table->even = 0;
// 		table->one = 1;
// 	}
// }

// void	*routine(void *data)
// {
// 	t_philo			*philo;
// 	int				left_fork;
// 	int				right_fork;

// 	philo = (t_philo *)data;
// 	if (philo->id == 1)
// 	{
// 		right_fork = 0;
// 		left_fork = philo->table->number_philo - 1;
// 	}
// 	else
// 	{
// 		right_fork = philo->id - 1;
// 		left_fork = philo->id - 2;
// 	}
// 	if (philo->table->number_philo > 1)
// 	{
// 		while (philo->table->philo_dead == 0)
// 		{
// 			// printf("%d", philo->can_eat);
// 			if (philo->can_eat == 1)
// 			{
// 				pthread_mutex_lock(&(philo->table->fork_mutex[left_fork]));
// 				pthread_mutex_lock(&(philo->table->fork_mutex[right_fork]));
// 				philo_fork(philo, left_fork);
// 				philo_fork(philo, right_fork);
// 				philo_eat(philo);
// 				pthread_mutex_unlock(&(philo->table->fork_mutex[left_fork]));
// 				pthread_mutex_unlock(&(philo->table->fork_mutex[right_fork]));
// 				philo_sleep(philo);
// 				philo_think(philo);
// 			}
// 		}
// 	}
// 	return (0);
// }

// void	*table_program(void *data)
// {
// 	t_table	*table;
// 	long	current_ms;
// 	int		i;
// 	int		counter;

// 	table = (t_table *)data;
// 	while (table->philo_dead == 0)
// 	{
// 		current_ms = get_current_time();
// 		printf("%ld %s", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 			{
// 				table->philo_dead = i + 1;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		counter = 0;
// 		while (i < table->number_philo)
// 		{
// 			counter = counter + table->philo[i].can_eat;
// 			i++;
// 		}
// 		// printf("%d -", counter);
// 		if (counter == 0)
// 		{
// 			if (table->number_philo % 2 == 0)
// 			{
// 				if (table->odd == 1)
// 				{
// 					fill_table(table, 1, table->number_philo);
// 					table->odd = 0;
// 					table->even = 1;
// 				}
// 				else if (table->even == 1)
// 				{
// 					fill_table(table, 0, table->number_philo);
// 					table->odd = 1;
// 					table->even = 0;
// 				}
// 			}
// 			else
// 			{
// 				if (table->one == 1)
// 				{
// 					fill_table(table, 0, 1);
// 					table->odd = 1;
// 					table->one = 0;
// 				}
// 				else if (table->odd == 1)
// 				{
// 					fill_table(table, 2, table->number_philo);
// 					table->odd = 0;
// 					table->even = 1;
// 				}
// 				else if (table->even == 1)
// 				{
// 					fill_table(table, 1, table->number_philo);
// 					table->one = 1;
// 					table->even = 0;
// 				}
// 			}
// 		}
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			printf("%d", table->philo[i].can_eat);
// 			i++;
// 		}
// 		printf("\n");
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
			// current_ms - table->start_time, table->philo_dead);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_table	*table;
// 	int		i;

// 	check_arguments(argc);
// 	printf("%s", argv[0]);
// 	table = malloc(sizeof(t_table));
// 	table->start_time = get_current_time();
// 	store_data(table, argv);

// 	pthread_mutex_init(&(table->dead_lock), NULL);
// 	// pthread_mutex_init(&(table->full_lock), NULL);
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_mutex_init(&(table->fork_mutex[i]), NULL);
// 		i++;
// 	}
// 	pthread_create(&table->tid, NULL, table_program, table);
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_create(&(table->philo[i].tid), NULL, routine, &table->philo[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_join(table->philo[i].tid, NULL);
// 		i++;
// 	}
// 	pthread_join(table->tid, NULL);
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_mutex_destroy(&(table->fork_mutex[i]));
// 		i++;
// 	}
// 	pthread_mutex_destroy(&(table->dead_lock));
// 	// pthread_mutex_destroy(&(table->full_lock));
// 	free(table->philo);
// 	free(table);
// 	return (0);
// }

// int	fonction(t_philo *data)
// {
// 	int	temp;
// 	t_philo		*philo;

// 	philo = (t_philo *)data;
// 	temp = 0;
// 	pthread_mutex_lock(&philo->table->dead_lock);
// 	temp = philo->table->philo_dead;
// 	pthread_mutex_unlock(&philo->table->dead_lock);
// 	return (temp);
// }

// void	*thread_routine(void *data)
// {
// 	long			current_ms;
// 	t_philo		*philo;
// 	// int				left_fork;
// 	// int				right_fork;

// 	philo = (t_philo *)data;
// 	// if (philo->id == 1)
// 	// {
// 	// 	right_fork = 0;
// 	// 	left_fork = philo->table->number_philo - 1;
// 	// }
// 	// else
// 	// {
// 	// 	right_fork = philo->id - 1;
// 	// 	left_fork = philo->id - 2;
// 	// }
// 	while (fonction(philo) == 0)
// 	{
// 		if (philo->can_eat == 1)
// 		{
// 		// pthread_mutex_lock(&(philo->table->fork_mutex[left_fork]));
// 		// pthread_mutex_lock(&(philo->table->fork_mutex[right_fork]));
// 		// philo_eat(philo);
// 		// pthread_mutex_unlock(&(philo->table->fork_mutex[left_fork]));
// 		// pthread_mutex_unlock(&(philo->table->fork_mutex[right_fork]));

// 		// pthread_mutex_lock(&philo->table->dead_lock);
// 		pthread_mutex_lock(&(philo->table->printf_lock));
// 		printf("philo %d\n", philo->id);
// 		pthread_mutex_unlock(&(philo->table->printf_lock));
// 		// write(1, "hey\n", 4);
// 		current_ms = get_current_time();
// 		pthread_mutex_lock(&(philo->table->printf_lock));
// 		philo->last_meal_start = get_current_time();
// 		pthread_mutex_unlock(&(philo->table->printf_lock));
// 		// usleep(100 * 1000);
// 		// pthread_mutex_unlock(&philo->table->dead_lock);
// 		pthread_mutex_lock(&(philo->table->printf_lock));
// 		philo->can_eat = 0;
// 		pthread_mutex_unlock(&(philo->table->printf_lock));
// 		}
// 	}
// 	return (0);
// }

// // void	philo_eat(t_philo *philo)
// // {
// // 	long			current_ms;
// // 	// int				temp;

// // 	// pthread_mutex_lock(&philo->table->dead_lock);
// // 	// temp = philo->table->philo_dead;
// // 	// pthread_mutex_unlock(&philo->table->dead_lock);
// // 	if (philo->table->philo_dead != 0)
// // 		exit (1);
// // 	current_ms = get_current_time();
// // 	philo->last_meal_start = get_current_time();
// // 	// pthread_mutex_lock(&(philo->table->dead_lock));
// // 	printf("%ld %d %s\n",
	// 		current_ms - philo->table->start_time, philo->id, "is eating");
// // 	// pthread_mutex_unlock(&(philo->table->dead_lock));
// // 	usleep(philo->time_eat * 1000);
// // 	pthread_mutex_lock(&(philo->table->printf_lock));
// // 	philo->can_eat = 0;
// // 	pthread_mutex_unlock(&(philo->table->printf_lock));
// // 	// philo->number_meals++;
// // 	// philo->table->counter = 1;
// // 	// if (philo->number_meals >= philo->number_meals_full)
// // 	// {
// // 	// 	pthread_mutex_lock(&(philo->table->full_lock));
// // 	// 	philo->table->philo_full = philo->id;
// // 	// 	pthread_mutex_unlock(&(philo->table->full_lock));
// // 	// }
// // }

// int	fonction_time(t_philo *data, long current_ms)
// {
// 	long	temp;
// 	t_philo		*philo;

// 	philo = (t_philo *)data;
// 	temp = 0;
// 	pthread_mutex_lock(&philo->table->printf_lock);
// 	temp = philo->last_meal_start;
// 	pthread_mutex_unlock(&philo->table->printf_lock);
// 	return (current_ms - temp);
// }

// void	*thread_routine2(void *data)
// {
// 	t_table		*table;
// 	long		current_ms;
// 	int			i;
// 	int			counter;

// 	table = (t_table *)data;
// 	while (fonction(table->philo) == 0)
// 	{
// 		current_ms = get_current_time();
// 		printf("%ld %s", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (fonction_time(&table->philo[i], current_ms) >= table->time_die)
// 			{
// 				pthread_mutex_lock(&table->dead_lock);
// 				table->philo_dead = i + 1;
// 				pthread_mutex_unlock(&table->dead_lock);
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		counter = 0;
// 		while (i < table->number_philo)
// 		{
// 			pthread_mutex_lock(&(table->printf_lock));
// 			counter = counter + table->philo[i].can_eat;
// 			pthread_mutex_unlock(&(table->printf_lock));
// 			i++;
// 		}
// 		printf("counter %d\n", counter);
// 		if (counter == 0)
// 		{
// 			if (table->number_philo % 2 == 0)
// 			{
// 				if (table->odd == 1)
// 				{
// 					printf("b\n");
// 					fill_table(table, 1, table->number_philo);
// 					table->odd = 0;
// 					table->even = 1;
// 				}
// 				else if (table->even == 1)
// 				{
// 					printf("a\n");
// 					fill_table(table, 0, table->number_philo);
// 					table->odd = 1;
// 					table->even = 0;
// 				}
// 			}
// 			else
// 			{
// 				if (table->one == 1)
// 				{
// 					printf("a\n");
// 					fill_table(table, 0, 1);
// 					table->odd = 1;
// 					table->one = 0;
// 				}
// 				else if (table->odd == 1)
// 				{
// 					printf("b\n");
// 					fill_table(table, 1, table->number_philo);
// 					table->odd = 0;
// 					table->even = 1;
// 				}
// 				else if (table->even == 1)
// 				{
// 					printf("c\n");
// 					fill_table(table, 2, table->number_philo);
// 					table->even = 0;
// 					table->one = 1;
// 				}
// 			}
// 		}
// 		i = 0;
// 		pthread_mutex_lock(&(table->dead_lock));
// 		printf("table ");
// 		while (i < table->number_philo)
// 		{
// 			pthread_mutex_lock(&(table->printf_lock));
// 			printf("%d", table->philo[i].can_eat);
// 			pthread_mutex_unlock(&(table->printf_lock));
// 			i++;
// 		}
// 		pthread_mutex_unlock(&(table->dead_lock));

// 		pthread_mutex_lock(&table->dead_lock);
// 		printf("\n");
// 		pthread_mutex_unlock(&table->dead_lock);
// 		usleep(100 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
		// current_ms - table->start_time, table->philo_dead);
// 	// usleep(1000 * 1000);
// 	// pthread_mutex_lock(&table->dead_lock);
// 	// table->philo_dead = 1;
// 	// pthread_mutex_unlock(&table->dead_lock);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_table			*table;
// 	int				i;

// 	check_arguments(argc);
// 	table = malloc(sizeof(t_table));
// 	table->start_time = get_current_time();
// 	store_data(table, argv);
// 	pthread_mutex_init(&(table->dead_lock), NULL);
// 	pthread_mutex_init(&(table->printf_lock), NULL);
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_mutex_init(&(table->fork_mutex[i]), NULL);
// 		i++;
// 	}
// 	// i = 0;
// 	// while (i < table->number_philo)
// 	// {
// 	// 	pthread_create(&(table->philo[i].tid),
// NULL, thread_routine, &table->philo[i]);
// 	// 	i++;
// 	// }
// 	pthread_create(&(table->philo[0].tid), NULL,
// thread_routine, &table->philo[0]);
// 	pthread_create(&(table->philo[1].tid), NULL,
// thread_routine, &table->philo[1]);
// 	pthread_create(&table->tid, NULL, thread_routine2, table);
// 	// i = 0;
// 	// while (i < table->number_philo)
// 	// {
// 	// 	pthread_join(table->philo[i].tid, NULL);
// 	// 	i++;
// 	// }
// 	pthread_join(table->philo[0].tid, NULL);
// 	pthread_join(table->philo[1].tid, NULL);
// 	pthread_join(table->tid, NULL);
// 	pthread_mutex_destroy(&(table->dead_lock));
// 	pthread_mutex_destroy(&(table->printf_lock));
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_mutex_destroy(&(table->fork_mutex[i]));
// 		i++;
// 	}
// 	free(table->fork_mutex);
// 	free(table->philo);
// 	free(table);
// 	return (0);
// }

// //////////////////////////////// V2

// // int	fonction(t_philo *data)
// // {
// // 	int	temp;
// // 	t_philo		*philo;

// // 	philo = (t_philo *)data;
// // 	temp = 0;
// // 	pthread_mutex_lock(&philo->table->dead_lock);
// // 	temp = philo->table->philo_dead;
// // 	pthread_mutex_unlock(&philo->table->dead_lock);
// // 	return (temp);
// // }

// // void	*thread_routine(void *data)
// // {
// // 	t_philo		*philo;
// // 	int				left_fork;
// // 	int				right_fork;

// // 	philo = (t_philo *)data;
// // 	if (philo->id == 1)
// // 	{
// // 		right_fork = 0;
// // 		left_fork = philo->table->number_philo - 1;
// // 	}
// // 	else
// // 	{
// // 		right_fork = philo->id - 1;
// // 		left_fork = philo->id - 2;
// // 	}
// // 	while (fonction(philo) == 0)
// // 	{
// // 		if (philo->can_eat == 1)
// // 		{
// // 		pthread_mutex_lock(&(philo->table->fork_mutex[left_fork]));
// // 		pthread_mutex_lock(&(philo->table->fork_mutex[right_fork]));
// // 		// philo_fork(philo, left_fork);
// // 		// philo_fork(philo, right_fork);
// // 		philo_eat(philo);
// // 		pthread_mutex_unlock(&(philo->table->fork_mutex[left_fork]));
// // 		// philo_sleep(philo);
// // 		// philo_think(philo);
// // 		pthread_mutex_unlock(&(philo->table->fork_mutex[right_fork]));

// // 		// pthread_mutex_lock(&philo->table->dead_lock);
// // 		// printf("hey\n");
// // 		// // write(1, "hey\n", 4);
// // 		// pthread_mutex_unlock(&philo->table->dead_lock);
// // 		// usleep(100 * 1000);
// // 		}
// // 	}
// // 	return (0);
// // }

// void	*thread_routine2(void *data)
// {
// 	t_table		*table;
// 	long		current_ms;
// 	int			i;
// 	int			counter;

// 	table = (t_table *)data;
// 	while (fonction(table->philo) == 0)
// 	{
// 		current_ms = get_current_time();
// 		printf("%ld %s", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 			{
// 				pthread_mutex_lock(&table->dead_lock);
// 				table->philo_dead = i + 1;
// 				pthread_mutex_unlock(&table->dead_lock);
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		counter = 0;
// 		while (i < table->number_philo)
// 		{
// 			pthread_mutex_lock(&(table->printf_lock));
// 			counter = counter + table->philo[i].can_eat;
// 			pthread_mutex_unlock(&(table->printf_lock));
// 			i++;
// 		}

// 		if (counter == 0)
// 		{
// 			if (table->number_philo % 2 == 0)
// 			{
// 				if (table->odd == 1)
// 				{
// 					fill_table(table, 1, table->number_philo);
// 					table->odd = 0;
// 					table->even = 1;
// 				}
// 				else if (table->even == 1)
// 				{
// 					fill_table(table, 0, table->number_philo);
// 					table->odd = 1;
// 					table->even = 0;
// 				}
// 			}
// 			else
// 			{
// 				if (table->one == 1)
// 				{
// 					fill_table(table, 0, 1);
// 					table->odd = 1;
// 					table->one = 0;
// 				}
// 				else if (table->odd == 1)
// 				{
// 					fill_table(table, 2, table->number_philo);
// 					table->odd = 0;
// 					table->even = 1;
// 				}
// 				else if (table->even == 1)
// 				{
// 					fill_table(table, 1, table->number_philo);
// 					table->one = 1;
// 					table->even = 0;
// 				}
// 			}
// 		}
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			pthread_mutex_lock(&(table->printf_lock));
// 			printf("%d", table->philo[i].can_eat);
// 			pthread_mutex_unlock(&(table->printf_lock));
// 			i++;
// 		}
// 		pthread_mutex_lock(&table->dead_lock);
// 		printf("\n");
// 		pthread_mutex_unlock(&table->dead_lock);
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
	// current_ms - table->start_time, table->philo_dead);
// 	// usleep(1000 * 1000);
// 	// pthread_mutex_lock(&table->dead_lock);
// 	// table->philo_dead = 1;
// 	// pthread_mutex_unlock(&table->dead_lock);
// 	return (0);
// }

// // int	main(int argc, char **argv)
// // {
// // 	t_table			*table;
// // 	int				i;

// // 	check_arguments(argc);
// // 	table = malloc(sizeof(t_table));
// // 	table->start_time = get_current_time();
// // 	store_data(table, argv);
// // 	pthread_mutex_init(&(table->dead_lock), NULL);
// // 	pthread_mutex_init(&(table->printf_lock), NULL);
// // 	i = 0;
// // 	while (i < table->number_philo)
// // 	{
// // 		pthread_mutex_init(&(table->fork_mutex[i]), NULL);
// // 		i++;
// // 	}
// // 	i = 0;
// // 	while (i < table->number_philo)
// // 	{
// // 		pthread_create(&(table->philo[i].tid),
// NULL, thread_routine, &table->philo[i]);
// // 		i++;
// // 	}
// // 	pthread_create(&table->tid, NULL, thread_routine2, table);
// // 	i = 0;
// // 	while (i < table->number_philo)
// // 	{
// // 		pthread_join(table->philo[i].tid, NULL);
// // 		i++;
// // 	}
// // 	pthread_join(table->tid, NULL);
// // 	pthread_mutex_destroy(&(table->dead_lock));
// // 	pthread_mutex_destroy(&(table->printf_lock));
// // 	i = 0;
// // 	while (i < table->number_philo)
// // 	{
// // 		pthread_mutex_destroy(&(table->fork_mutex[i]));
// // 		i++;
// // 	}
// // 	free(table->fork_mutex);
// // 	free(table->philo);
// // 	free(table);
// // 	return (0);
// // }

// /////////////////////////////// NO DATA RACE V2

// // int	fonction(t_table *counter)
// // {
// // 	int	temp;

// // 	temp = 0;
// // 	pthread_mutex_lock(&counter->dead_lock);
// // 	temp = counter->philo_dead;
// // 	pthread_mutex_unlock(&counter->dead_lock);
// // 	return (temp);
// // }

// // void	*thread_routine(void *data)
// // {
// // 	t_table		*table;

// // 	table = (t_table *)data;
// // 	while (fonction(table) == 0)
// // 	{
// // 		printf("hey\n");
// // 		usleep(100 * 1000);
// // 	}
// // 	return (0);
// // }

// // void	*thread_routine2(void *data)
// // {
// // 	t_table		*table;

// // 	table = (t_table *)data;
// // 	usleep(1000 * 1000);
// // 	pthread_mutex_lock(&table->dead_lock);
// // 	table->philo_dead = 1;
// // 	pthread_mutex_unlock(&table->dead_lock);
// // 	return (0);
// // }

// // int	main(void)
// // {
// // 	pthread_t		tid1;
// // 	pthread_t		tid2;
// // 	t_table		*table;

// // 	table = malloc(sizeof(t_table));
// // 	table->philo = malloc(sizeof(t_philo) * (1+1));
// // 	table->philo_dead = 0;
// // 	pthread_mutex_init(&table->dead_lock, NULL);
// // 	pthread_create(&tid1, NULL, thread_routine, table);
// // 	pthread_create(&tid2, NULL, thread_routine2, table);
// // 	pthread_join(tid1, NULL);
// // 	pthread_join(tid2, NULL);
// // 	pthread_mutex_destroy(&table->dead_lock);
// // 	free(table->philo);
// // 	free(table);
// // 	return (0);
// // }

// /////////////////////////////// NO DATA RACE

// // typedef	struct s_monitor
// // {
// // 	unsigned int	hook;
// // } t_monitor;

// // typedef struct s_counter
// // {
// // 	pthread_mutex_t	count_mutex;
// // 	unsigned int	count;
// // 	t_monitor		monitor;
// // }	t_counter;

// // int	fonction(t_counter *counter)
// // {
// // 	int	temp;

// // 	temp = 0;
// // 	pthread_mutex_lock(&counter->count_mutex);
// // 	temp = counter->monitor.hook;
// // 	pthread_mutex_unlock(&counter->count_mutex);
// // 	return (temp);
// // }

// // void	*thread_routine(void *data)
// // {
// // 	t_counter		*counter;

// // 	counter = (t_counter *)data;
// // 	while (fonction(counter) == 0)
// // 	{
// // 		printf("hey\n");
// // 		usleep(100 * 1000);
// // 	}
// // 	return (0);
// // }

// // void	*thread_routine2(void *data)
// // {
// // 	t_counter		*counter;

// // 	counter = (t_counter *)data;
// // 	usleep(1000 * 1000);
// // 	pthread_mutex_lock(&counter->count_mutex);
// // 	counter->monitor.hook = 1;
// // 	pthread_mutex_unlock(&counter->count_mutex);
// // 	return (0);
// // }

// // int	main(void)
// // {
// // 	pthread_t		tid1;
// // 	pthread_t		tid2;
// // 	t_counter		counter;

// // 	counter.count = 0;
// // 	counter.monitor.hook = 0;
// // 	pthread_mutex_init(&counter.count_mutex, NULL);
// // 	pthread_create(&tid1, NULL, thread_routine, &counter);
// // 	pthread_create(&tid2, NULL, thread_routine2, &counter);
// // 	pthread_join(tid1, NULL);
// // 	pthread_join(tid2, NULL);
// // 	pthread_mutex_destroy(&counter.count_mutex);
// // 	return (0);
// // }

/////////////////////////// NO DATA RACE

// typedef struct s_counter
// {
// 	pthread_mutex_t	count_mutex;
// 	unsigned int	count;
// 	int				valeur;
// }	t_counter;

// int	fonction(t_counter *counter)
// {
// 	int	temp;

// 	temp = 0;
// 	pthread_mutex_lock(&counter->count_mutex);
// 	temp = counter->valeur;
// 	pthread_mutex_unlock(&counter->count_mutex);
// 	return (temp);
// }

// void	*thread_routine(void *data)
// {
// 	t_counter		*counter;

// 	counter = (t_counter *)data;
// 	while (fonction(counter) == 0)
// 	{
// 		pthread_mutex_lock(&counter->count_mutex);
// 		printf("%d", counter->valeur);
// 		pthread_mutex_unlock(&counter->count_mutex);
// 		usleep(100 * 1000);
// 	}
// 	return (0);
// }

// void	*thread_routine2(void *data)
// {
// 	t_counter		*counter;

// 	counter = (t_counter *)data;
// 	pthread_mutex_lock(&counter->count_mutex);
// 	counter->valeur = 1;
// 	pthread_mutex_unlock(&counter->count_mutex);
// 	return (0);
// }

// int	main(void)
// {
// 	pthread_t		tid1;
// 	pthread_t		tid2;
// 	t_counter		counter;

// 	counter.count = 0;
// 	counter.valeur = 0;
// 	pthread_mutex_init(&counter.count_mutex, NULL);
// 	pthread_create(&tid1, NULL, thread_routine, &counter);
// 	pthread_create(&tid2, NULL, thread_routine2, &counter);
// 	pthread_join(tid1, NULL);
// 	pthread_join(tid2, NULL);
// 	printf("%u\n", counter.count);
// 	pthread_mutex_destroy(&counter.count_mutex);
// 	return (0);
// }

///////////////////////////// ROUTINE EVEN vs ODD

// void	*routine(void *data)
// {
// 	t_philo			*philo;
// 	int				i;
// 	int				group;

// 	philo = (t_philo *)data;
// 	if (philo->id == 1)
// 		i = 0;
// 	else
// 		i = philo->id - 2;
// 	while (philo->table->philo_dead == 0)
// 	{
// 		if (philo->id % 2 == 1)
// 			group = philo->table->group_odd;
// 		else if (philo->id % 2 == 0)
// 			group = philo->table->group_even;
// 		if (group == 1)
// 		{
// 			pthread_mutex_lock(&(philo->table->fork_mutex[i]));
// 			pthread_mutex_lock(&(philo->table->fork_mutex[i + 1]));
// 			philo_fork(philo);
// 			philo_fork(philo);
// 			philo_eat(philo);
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[i]));
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[i + 1]));
// 			philo_sleep(philo);
// 			philo_think(philo);
// 		}
// 	}
// 	return (0);
// }

// void	*table_program(void *data)
// {
// 	t_table	*table;
// 	long	current_ms;
// 	int		i;
// 	int		counter_odd;
// 	int		counter_even;

// 	counter_odd = 1;
// 	counter_even = 1;
// 	table = (t_table *)data;
// 	table->group_odd = 1;
// 	while (table->philo_dead == 0)
// 	{
// 		current_ms = get_current_time();
// 		printf("%ld %s\n", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 				table->philo_dead = i + 1;
// 			i++;
// 		}
// 		if (table->group_odd == 1 &&
// table->philo[0].number_meals == counter_odd)
// 		{
// 			table->group_odd = 0;
// 			table->group_even = 1;
// 			counter_odd++;
// 		}
// 		else if (table->group_even == 1 &&
// table->philo[1].number_meals == counter_even)
// 		{
// 			table->group_odd = 1;
// 			table->group_even = 0;
// 			counter_even++;
// 		}
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
// current_ms - table->start_time, table->philo_dead);
// 	return (0);
// }

///////////////////////////// OLD ROUTINE NOT REFACTORED

// void	*routine(void *data)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)data;
// 	if (philo->id == 1)
// 	{
// 		while (philo->table->philo_dead == 0)
// 		{
// 			pthread_mutex_lock(&(philo->table->fork_mutex[0]));
// 			pthread_mutex_lock(&(philo->table->fork_mutex[1]));
// 			philo_fork(philo);
// 			philo_fork(philo);
// 			philo_eat(philo);
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[0]));
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[1]));
// 			philo_sleep(philo);
// 			philo_think(philo);
// 		}
// 	}
// 	else
// 	{
// 		while (philo->table->philo_dead == 0)
// 		{
// 			pthread_mutex_lock(&(philo->table->fork_mutex[philo->id - 2]));
// 			pthread_mutex_lock(&(philo->table->fork_mutex[philo->id - 1]));
// 			philo_fork(philo);
// 			philo_fork(philo);
// 			philo_eat(philo);
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id - 2]));
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id - 1]));
// 			philo_sleep(philo);
// 			philo_think(philo);
// 		}
// 	}
// 	return (0);
// }

/////////////////////////////// ROUTINE RANDOM

// void	*table_program(void *data)
// {
// 	t_table	*table;
// 	long	current_ms;
// 	int		i;

// 	table = (t_table *)data;
// 	while (table->philo_dead == 0)
// 	{
// 		current_ms = get_current_time();
// 		// printf("%ld %s\n", current_ms - table->start_time, "--");
// 		printf("%ld %s", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 				table->philo_dead = i + 1;
// 			i++;
// 		}
// 		if (table->philo[0].number_meals <= table->philo[1].number_meals
// 			&& table->philo[0].number_meals <=
				// table->philo[table->number_philo - 1].number_meals
// 			&& table->philo[0].last_meal_start <=
				// table->philo[1].last_meal_start
// 			&& table->philo[0].last_meal_start <=
				// table->philo[table->number_philo - 1].last_meal_start)
// 			table->philo[0].can_eat = 1;
// 		if (table->philo[table->number_philo - 1].number_meals <=
				// table->philo[0].number_meals
// 			&& table->philo[table->number_philo - 1].number_meals <=
				// table->philo[table->number_philo - 2].number_meals
// 			&& table->philo[table->number_philo - 1].last_meal_start <=
				// table->philo[0].last_meal_start
// 			&& table->philo[table->number_philo - 1].last_meal_start <=
				// table->philo[table->number_philo - 2].last_meal_start)
// 			table->philo[table->number_philo - 1].can_eat = 1;
// 		i = 1;
// 		while (i < table->number_philo - 1)
// 		{
// 			if (table->philo[i].number_meals <= table->philo[i - 1].number_meals
// 				&& table->philo[i].number_meals <=
					// table->philo[i + 1].number_meals
// 				&& table->philo[i].last_meal_start <=
					// table->philo[i - 1].last_meal_start
// 				&& table->philo[i].last_meal_start <=
					// table->philo[i + 1].last_meal_start)
// 				table->philo[i].can_eat = 1;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			printf("%d", table->philo[i].can_eat);
// 			i++;
// 		}
// 		printf("\n");
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
			// current_ms - table->start_time, table->philo_dead);
// 	return (0);
// }

//////////////////////////////////////////// RANDOM + ODD + EVEN

// void	*table_program(void *data)
// {
// 	t_table	*table;
// 	long	current_ms;
// 	int		i;
// 	int		counter;
// 	int		odd;

// 	odd = 0;
// 	table = (t_table *)data;
// 	while (table->philo_dead == 0)
// 	{
// 		current_ms = get_current_time();
// 		// printf("%ld %s\n", current_ms - table->start_time, "--");
// 		printf("%ld %s", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 				table->philo_dead = i + 1;
// 			i++;
// 		}
// 		i = 0;
// 		counter = 0;
// 		while (i < table->number_philo)
// 		{
// 			counter = counter + table->philo[i].can_eat;
// 			i++;
// 		}
// 		printf("%d -", counter);
// 		i = 0;
// 		if (counter == 0)
// 		{
// 			if (odd == 0)
// 				odd = 1;
// 			else
// 				odd = 0;
// 			while (i < table->number_philo)
// 			{
// 				if (i % 2 == odd)
// 					table->philo[i].can_eat = 1;
// 				else
// 					table->philo[i].can_eat = 0;
// 				i++;
// 			}
// 		}
// 		// if (table->counter == 1)
// 		// {
// 		// if (table->philo[0].number_meals <= table->philo[1].number_meals
// 		// 	&& table->philo[0].number_meals <=
				// table->philo[table->number_philo - 1].number_meals
// 		// 	&& table->philo[0].last_meal_start <=
				// table->philo[1].last_meal_start
// 		// 	&& table->philo[0].last_meal_start <=
				// table->philo[table->number_philo - 1].last_meal_start)
// 		// 	table->philo[0].can_eat = 1;
// 		// if (table->philo[table->number_philo - 1].number_meals <=
				// table->philo[0].number_meals
// 		// 	&& table->philo[table->number_philo - 1].number_meals <=
				// table->philo[table->number_philo - 2].number_meals
// 		// 	&& table->philo[table->number_philo - 1].last_meal_start <=
				// table->philo[0].last_meal_start
// 		// 	&& table->philo[table->number_philo - 1].last_meal_start <=
				// table->philo[table->number_philo - 2].last_meal_start)
// 		// 	table->philo[table->number_philo - 1].can_eat = 1;
// 		// i = 1;
// 		// while (i < table->number_philo - 1)
// 		// {
// 		// 	if (table->philo[i].number_meals <= table->philo[i - 1].number_meals
// 		// 		&& table->philo[i].number_meals <=
					// table->philo[i + 1].number_meals
// 		// 		&& table->philo[i].last_meal_start <=
					// table->philo[i - 1].last_meal_start
// 		// 		&& table->philo[i].last_meal_start <=
					// table->philo[i + 1].last_meal_start)
// 		// 		table->philo[i].can_eat = 1;
// 		// 	i++;
// 		// }
// 		// }
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			printf("%d", table->philo[i].can_eat);
// 			i++;
// 		}
// 		printf("\n");
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
			// current_ms - table->start_time, table->philo_dead);
// 	return (0);
// }

//////////////////////////////////////////// RANDOM + ODD + EVEN V2

// void	*table_program(void *data)
// {
// 	t_table	*table;
// 	long	current_ms;
// 	int		i;
// 	int		change;
// 	int		counter;
// 	int		expected;

// 	change = 0;
// 	expected = 0;
// 	table = (t_table *)data;
// 	while (table->philo_dead == 0)
// 	{
// 		current_ms = get_current_time();
// 		printf("%ld %s", current_ms - table->start_time, "--");
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 				table->philo_dead = i + 1;
// 			i++;
// 		}
// 		i = 0;
// 		counter = 0;
// 		while (i < table->number_philo)
// 		{
// 			if (current_ms - table->philo[i].last_meal_start >= table->time_die)
// 				table->philo_dead = i + 1;
// 			i++;
// 			i++;
// 		}
// 		i = 1;
// 		while (i < table->number_philo - 1)
// 		{
// 			if (table->philo[i].number_meals <= table->philo[i - 1].number_meals
// 				&& table->philo[i].number_meals <=
					// table->philo[i + 1].number_meals
// 				&& table->philo[i].last_meal_start <=
					// table->philo[i - 1].last_meal_start
// 				&& table->philo[i].last_meal_start <=
					// table->philo[i + 1].last_meal_start)
// 				table->philo[i].can_eat = 1;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < table->number_philo)
// 		{
// 			printf("%d", table->philo[i].can_eat);
// 			i++;
// 		}
// 		printf("\n");
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
			// current_ms - table->start_time, table->philo_dead);
// 	return (0);
// }

///////////////////////////////////// CA MARCHE

// long	get_current_time(void)
// {
// 	struct timeval	current;
// 	long			current_ms;

// 	gettimeofday(&current, NULL);
// 	current_ms = current.tv_sec * 1000 + current.tv_usec / 1000;
// 	return (current_ms);
// }

// void	print_current_time(int id, t_philo *philo, char *str)
// {
// 	long	current_ms;

// 	current_ms = get_current_time();
// 	printf("%ld %d %s\n", current_ms - philo->table->start_time, id, str);
// }

// // void	check_death_time(t_philo *philo)
// // {
// // 	long			current_ms;

// // 	current_ms = get_current_time();
// // 	if (current_ms - philo->last_eat >= philo->time_die)
// // 	{
// // 		pthread_mutex_lock(&(philo->table->dead_lock));
// // 		philo->table->philo_dead = philo->id;
// // 		philo->table->death_time = current_ms;
// // 		pthread_mutex_unlock(&(philo->table->dead_lock));
// // 	}
// // }

// void	philo_think(t_philo *philo)
// {
// 	// check_death_time(philo);
// 	// if (philo->table->philo_dead != 0 || philo->table->philo_full != 0)
// 	// 	exit (1);
// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	print_current_time(philo->id, philo, "is thinking");
// 	// usleep(100 * 1000);
// }

// void	philo_sleep(t_philo *philo)
// {
// 	// check_death_time(philo);
// 	// if (philo->table->philo_dead != 0 || philo->table->philo_full != 0)
// 	// 	exit (1);
// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	print_current_time(philo->id, philo, "is sleeping");
// 	usleep(philo->time_sleep * 1000);
// }

// void	philo_fork(t_philo *philo)
// {
// 	// check_death_time(philo);
// 	// if (philo->table->philo_dead != 0 || philo->table->philo_full != 0)
// 	// 	exit (1);
// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	print_current_time(philo->id, philo, "has taken a fork");
// }

// void	philo_eat(t_philo *philo)
// {
// 	// check_death_time(philo);
// 	// if (philo->table->philo_dead != 0 || philo->table->philo_full != 0)
// 	// 	exit (1);
// 	if (philo->table->philo_dead != 0)
// 		exit (1);
// 	philo->last_eat = get_current_time();
// 	red();
// 	print_current_time(philo->id, philo, "is eating");
// 	reset();
// 	usleep(philo->time_eat * 1000);
// 	// philo->number_meals++;
// 	// if (philo->number_meals >= philo->eat_number)
// 	// {
// 	// 	pthread_mutex_lock(&(philo->table->full_lock));
// 	// 	philo->table->philo_full = philo->id;
// 	// 	pthread_mutex_unlock(&(philo->table->full_lock));
// 	// }
// }

// void	*routine(void *data)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)data;
// 	if (philo->id == 1)
// 	{
// 		while (1)
// 		{
// 			if (philo->table->philo_dead != 0)
// 				break ;
// 			pthread_mutex_lock(&(philo->table->fork_mutex[0]));
// 			pthread_mutex_lock(&(philo->table->fork_mutex[1]));
// 			philo_fork(philo);
// 			philo_fork(philo);
// 			philo_eat(philo);
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[0]));
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[1]));
// 			philo_sleep(philo);
// 			philo_think(philo);
// 		}
// 	}
// 	else
// 	{
// 		while (1)
// 		{
// 			pthread_mutex_lock(&(philo->table->fork_mutex[philo->id - 2]));
// 			pthread_mutex_lock(&(philo->table->fork_mutex[philo->id - 1]));
// 			philo_fork(philo);
// 			philo_fork(philo);
// 			philo_eat(philo);
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id - 2]));
// 			pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id - 1]));
// 			philo_sleep(philo);
// 			philo_think(philo);
// 		}
// 	}
// 	return (0);
// }

// void	store_data(t_table *table, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	table->number_philo = ft_atoi(argv[1]);
// 	table->philo_dead = 0;
// 	table->philo_full = 0;
// 	table->death_time = 0;
// 	table->philo = malloc(sizeof(t_philo) * (table->number_philo + 1));
// 	table->fork_mutex = malloc(sizeof(pthread_mutex_t)
		// * (table->number_philo + 1));
// 	while (i < table->number_philo)
// 	{
// 		table->philo[i].number_meals = 0;
// 		table->philo[i].id = i + 1;
// 		table->philo[i].time_die = ft_atoi(argv[2]);
// 		table->philo[i].time_eat = ft_atoi(argv[3]);
// 		table->philo[i].time_sleep = ft_atoi(argv[4]);
// 		table->philo[i].eat_number = ft_atoi(argv[5]);
// 		table->philo[i].table = table;
// 		table->philo[i].last_eat = table->start_time;
// 		i++;
// 	}
// }

// void	*table_program(void *data)
// {
// 	t_table	*table;
// 	long	current_ms;
// 	int		i;

// 	i = 0;
// 	table = (t_table *)data;
// 	while (1)
// 	{
// 		current_ms = get_current_time();
// 		printf("%ld %d %s\n", current_ms - table->start_time, 0, "monitor");
// 		// while (i < table->number_philo)
// 		// {
// 		// 	if (current_ms - philo->last_eat)
// 		// 	i++;
// 		// }
// 		// if (current_ms - philo->last_eat >= philo->time_die)
// 		// {
// 		// pthread_mutex_lock(&(philo->table->dead_lock));
// 		// philo->table->philo_dead = philo->id;
// 		// philo->table->death_time = current_ms;
// 		// pthread_mutex_unlock(&(philo->table->dead_lock));
// 		// }
// 		if (table->philo_dead != 0)
// 			break ;
// 		usleep(10 * 1000);
// 	}
// 	// if (table->philo_full != 0)
// 	// 	printf("%d full", table->philo_full);
// 	if (table->philo_dead != 0)
// 		printf("%ld %d died",
			// current_ms - table->start_time, table->philo_dead);
// 	return (0);
// }

// void	*test_routine(void *data)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)data;

// 	usleep(2000 * 1000);
// 	// pthread_mutex_lock(&(philo->table->dead_lock));
// 	philo->table->philo_dead = 1;
// 	// pthread_mutex_unlock(&(philo->table->dead_lock));
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_table	*table;
// 	int		i;

// 	check_arguments(argc);
// 	table = malloc(sizeof(t_table));
// 	table->start_time = get_current_time();
// 	store_data(table, argv);

// 	pthread_mutex_init(&(table->dead_lock), NULL);
// 	// pthread_mutex_init(&(table->full_lock), NULL);
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_mutex_init(&(table->fork_mutex[i]), NULL);
// 		i++;
// 	}

// 	pthread_create(&table->tid, NULL, table_program, table);
// 	pthread_create(&table->tidtest, NULL, test_routine, &table->philo[0]);

// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_create(&(table->philo[i].tid), NULL, routine, &table->philo[i]);
// 		i++;
// 	}

// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_join(table->philo[i].tid, NULL);
// 		i++;
// 	}
// 	pthread_join(table->tid, NULL);
// 	pthread_join(table->tidtest, NULL);
// 	i = 0;
// 	while (i < table->number_philo)
// 	{
// 		pthread_mutex_destroy(&(table->fork_mutex[i]));
// 		i++;
// 	}
// 	pthread_mutex_destroy(&(table->dead_lock));
// 	// pthread_mutex_destroy(&(table->full_lock));
// 	return (0);
// }

///////////////////////////////////// PTHREAD_JOIN AND PTHREAD CREATE

// void	*table_routine(void *data)
// {
// 	t_table	*table;

// 	table = (t_table *)data;
// 	while (table->philo_dead == 0)
// 	{
// 		print_current_time(0, table->philo, "monitor");
// 		usleep(10 * 1000);
// 	}
// 	pthread_mutex_lock(&(table->dead_lock));
// 	if (table->philo_dead == 1)
// 		print_current_time(0, table->philo, "death");
// 	pthread_mutex_unlock(&(table->dead_lock));
// 	return (0);
// }

// void	*test_routine(void *data)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)data;

// 	usleep(2000 * 1000);
// 	pthread_mutex_lock(&(philo->table->dead_lock));
// 	philo->table->philo_dead = 1;
// 	pthread_mutex_unlock(&(philo->table->dead_lock));
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_table	*table;

// 	check_arguments(argc);
// 	table = malloc(sizeof(t_table));
// 	table->start_time = get_current_time();
// 	store_data(table, argv);

// 	pthread_mutex_init(&(table->dead_lock), NULL);

// 	pthread_create(&table->tid, NULL, table_routine, table);
// 	pthread_create(&table->tidtest, NULL, test_routine, &table->philo[0]);

// 	pthread_join(table->tid, NULL);
// 	pthread_join(table->tidtest, NULL);
// 	pthread_mutex_destroy(&(table->dead_lock));
// 	return (0);
// }

///////////////////////////////////// MALLOC TABLE->FORK->MUTEX

// void	*routine(void *data)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)data;
// 	printf("id is %d\n", philo->id);
// 	return (0);
// }

// void	store_data(t_table *table, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	table->number_philo = ft_atoi(argv[1]);
// 	table->philo = malloc(sizeof(t_philo) * (table->number_philo + 1));
	// table->fork_mutex = malloc(sizeof(pthread_mutex_t)
	// 	* (table->number_philo + 1));
// 	while (i < table->number_philo)
// 	{
// 		table->philo[i].id = i + 1;
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_table	*table;

// 	check_arguments(argc);
// 	table = malloc(sizeof(t_table));
// 	store_data(table, argv);

// 	pthread_mutex_init(&(table->fork_mutex[0]), NULL);
// 	pthread_mutex_init(&(table->fork_mutex[1]), NULL);
// 	pthread_mutex_init(&(table->dead_lock), NULL);
// 	pthread_mutex_init(&(table->full_lock), NULL);

// 	pthread_create(&(table->philo[0].tid), NULL, routine, &table->philo[0]);
// 	pthread_create(&(table->philo[1].tid), NULL, routine, &table->philo[1]);
// 	pthread_join(table->philo[0].tid, NULL);
// 	pthread_join(table->philo[1].tid, NULL);

// 	pthread_mutex_destroy(&(table->fork_mutex[0]));
// 	pthread_mutex_destroy(&(table->fork_mutex[1]));
// 	pthread_mutex_destroy(&(table->dead_lock));
// 	pthread_mutex_destroy(&(table->full_lock));

// 	free(table->fork_mutex);
// 	free(table->philo);
// 	free(table);
// 	return (0);
// }