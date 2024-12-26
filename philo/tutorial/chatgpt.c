/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chatgpt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:34:56 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/28 16:36:53 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void	*print_message(void *ptr)
{
	char	*message;

	message = (char *)ptr;
	printf("%s\n", message);
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	char		*message1;
	char		*message2;

	message1 = "Hello from Thread 1!";
	message2 = "Hello from Thread 2!";
	pthread_create(&thread1, NULL, print_message, (void *)message1);
	pthread_create(&thread2, NULL, print_message, (void *)message2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}
