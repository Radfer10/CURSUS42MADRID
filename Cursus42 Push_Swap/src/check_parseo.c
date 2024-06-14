/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parseo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:58:24 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 21:08:31 by rde-migu         ###   ########.fr       */
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
