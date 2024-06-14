/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parseo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:54:26 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 21:02:58 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	return ((int)ft_atoll(str));
}

char	*ft_allocate_and_copy_string(const char *str, int start, int len)
{
	char	*new_str;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	strncpy(new_str, &str[start], len);
	new_str[len] = '\0';
	return (new_str);
}

char	**ft_split_strings(const char *str, char delimiter, char **result)
{
	int	i;
	int	start;
	int	index;

	i = 0;
	start = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
		{
			result[index++] = ft_allocate_and_copy_string(str, start, i
					- start);
			start = i + 1;
		}
		i++;
	}
	result[index] = ft_allocate_and_copy_string(str, start, i - start);
	result[index + 1] = NULL;
	return (result);
}

char	**ft_split(const char *str, char delimiter)
{
	int		count;
	int		i;
	char	**result;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			count++;
		i++;
	}
	result = malloc((count + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	return (ft_split_strings(str, delimiter, result));
}
