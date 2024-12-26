/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:42:40 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/17 18:07:06 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long	ft_atoi(const char *string)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (string[i] == ' ' || string[i] == '\f'
		|| string[i] == '\n' || string[i] == '\r'
		|| string[i] == '\t' || string[i] == '\v')
	i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (string[i] != '\0' && string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + string[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	getlength(long longnum)
{
	int		size;

	size = 0;
	if (longnum == 0)
		return (1);
	else if (longnum < 0)
		size++;
	while (longnum != 0)
	{
		size++;
		longnum = longnum / 10;
	}
	return (size);
}

static char	*copynumber(long longnum, int length)
{
	char	*string;

	string = (char *)malloc((length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	length--;
	if (longnum < 0)
	{
		string[0] = '-';
		longnum = -longnum;
	}
	else if (longnum == 0)
		string[0] = '0';
	while (longnum != 0)
	{
		string[length] = longnum % 10 + '0';
		longnum = longnum / 10;
		length--;
	}
	return (string);
}

char	*ft_itoa(int num)
{
	char	*string;
	long	longnum;
	int		length;

	longnum = (long)num;
	length = getlength(longnum);
	string = copynumber(longnum, length);
	return (string);
}
