/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parseo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:54:26 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 19:03:53 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	return (int)ft_atoll(str);
}

void	display_error(const char *message, int exit_code)
{
	fprintf(stderr, "%s\n", message);
	exit(exit_code);
}

char	**ft_split(const char *str, char delimiter)
{
	char	**result;
	int		count;
	int		i;
	int		start;
	int		index;

	count = 0;
	i = 0;
	// Counting the number of splits
	while (str[i])
	{
		if (str[i] == delimiter)
			count++;
		i++;
	}
	result = (char **)malloc((count + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
		{
			result[index] = (char *)malloc(i - start + 1);
			if (!result[index])
			{
				free_2d(result); // Free previously allocated memory
				return (NULL);
			}
			strncpy(result[index], &str[start], i - start);
			result[index][i - start] = '\0';
			index++;
			start = i + 1;
		}
		i++;
	}
	result[index] = (char *)malloc(i - start + 1);
	if (!result[index])
	{
		free_2d(result); // Free previously allocated memory
		return (NULL);
	}
	strncpy(result[index], &str[start], i - start);
	result[index][i - start] = '\0';
	result[index + 1] = NULL;
	return (result);
}

void	free_2d(char **array)
{
	int i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}