/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tommyjd93.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:47:08 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/28 16:47:15 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <pthread.h>

/////////////// MEMORY RACE

// int cont = 0;

// void  *routine()
// {
// 	int i;

// 	i = -1;
// 	while (++i < 1000000)
// 		cont++;
// 	return (NULL);
// }

// int main()
// {
// 	pthread_t tid1, tid2;

// 	pthread_create(&tid1, NULL, &routine, NULL);
// 	pthread_create(&tid2, NULL, &routine, NULL);

// 	pthread_join(tid1, NULL);
// 	pthread_join(tid2, NULL);
// 	printf("cont: %d\n", cont);
// }

/////////////// MUTEX

// int cont = 0;
// pthread_mutex_t lock;

// void  *routine()
// {
//   int i;

//   i = -1;
//   while (++i < 1000000)
//   {
//     pthread_mutex_lock(&lock);
//   	  cont++;
//     pthread_mutex_unlock(&lock);
//   }
//   return (NULL);
// }

// int main()
// {
//   pthread_t tid1, tid2;

//   pthread_mutex_init(&lock, NULL);
//   pthread_create(&tid1, NULL, &routine, NULL);
//   pthread_create(&tid2, NULL, &routine, NULL);

//   pthread_join(tid1, NULL);
//   pthread_join(tid2, NULL);
//   pthread_mutex_destroy(&lock);
//   printf("cont: %d\n", cont);
// }
