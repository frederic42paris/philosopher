/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   javapoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:45:54 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/28 16:45:54 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>  
// #include <pthread.h>  
// #include <semaphore.h>  
// #include <unistd.h>  

// pthread_t philosopher[5];
// pthread_mutex_t chopstick[5];

// void *func(void *arg)
// {
// 	int n = *(int *)arg;

// 	printf("\nPhilosopher %d is thinking.", n);
// 	pthread_mutex_lock(&chopstick[n]);
// 	pthread_mutex_lock(&chopstick[(n + 1) % 5]);
// 	printf("\nPhilosopher %d is eating.", n);
// 	sleep(3);
// 	pthread_mutex_unlock(&chopstick[n]);
// 	pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
// 	printf("\nPhilosopher %d Finished eating ", n);
// 	return NULL;
// }

// int main()
// {
// 	int i, k;
// 	void *message;

// 	for (i = 0; i< 5; i++)
// 	{
// 		k = pthread_mutex_init(&chopstick[i], NULL);
// 		if (k != 0)
// 		{
// 			printf("Failed to initialize the mutex\n");
// 			exit(1);
// 		}
// 	}
// 	for (i = 0; i< 5; i++)
// 	{
// 		k = pthread_create(&philosopher[i], NULL, func, (void *)&i);
// 		if (k != 0)
// 		{
// 			printf("Error in thread creation.\n");
// 			exit(1);
// 		}
// 	}
// 	for (i = 0; i< 5; i++)
// 	{
// 		k = pthread_join(philosopher[i], &message);
// 		if (k != 0)  
// 		{
// 			printf("Failed to join the thread.\n");
// 			exit(1);
// 		}
// 	}
// 	for (i = 0; i< 5; i++)
// 	{
// 		k = pthread_mutex_destroy(&chopstick[i]);
// 		if (k != 0)  
// 		{
// 			printf("Mutex destroyed.\n");  
// 			exit(1);  
// 		}
// 	}
// 	return 0;
// }