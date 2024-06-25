/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parseo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:58:24 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/24 19:00:38 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdbool.h>

int	check_digits(int argc, char **argv)
{
	int	i;
	int	count;
	int	j;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_range(char **s_numbers, t_stack **stack)
{
	int			i;
	long long	num;

	i = 0;
	while (s_numbers[i])
	{
		num = ft_atoll(s_numbers[i]);
		if (num > INT_MAX || num < INT_MIN || strlen(s_numbers[i]) > 11)
		{
			free_2d(s_numbers);
			free_stack(stack);
			display_error("Error", 1);
		}
		i++;
	}
}

int	contains_invalid_signs(const char *str)
{
	while (*str)
	{
		if ((*str == '-' && *(str + 1) == '-') || (*str == '+' && *(str
					+ 1) == '+'))
		{
			return (1);
		}
		if ((*str == '-' || *str == '+') && !(*(str + 1) >= '0' && *(str
					+ 1) <= '9'))
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	contains_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->content == value)
		{
			return (1);
		}
		if (stack->next)
		{
			if ((stack->content == '-' && stack->next->content == '-')
				|| (stack->content == '+' && stack->next->content == '+'))
			{
				return (1);
			}
		}
		stack = stack->next;
	}
	return (0);
}

int	contains_non_numeric_characters(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		{
			return (1);
		}
		str++;
	}
	return (0);
}
