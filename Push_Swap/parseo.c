/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:39 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 19:13:24 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digits(int argc, char **argv)
{
	int i, j, count = 0;
	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
			{
				return (-1);
			}
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
			{
				count++;
			}
			j++;
		}
	}
	return (count);
}

int	contains_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->content == value)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
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

void	add_to_stack(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		fprintf(stderr, "Memory allocation error\n");
		free_stack(stack);
		exit(1);
	}
	new_node->content = num;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

void	arg_parse(t_push_swap *ps, int argc, char **argv)
{
	char	**s_numbers;
	int		num;

	for (int i = 1; i < argc; i++)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
		{
			free_stack(&ps->a);
			display_error("Error", 1);
		}
		check_range(s_numbers, &ps->a);
		for (int k = 0; s_numbers[k]; k++)
		{
			num = ft_atoi(s_numbers[k]);
			if (contains_duplicate(ps->a, num))
			{
				free_2d(s_numbers);
				free_stack(&ps->a);
				display_error("Error", 1);
			}
			add_to_stack(&ps->a, num);
			ps->a_size++;
		}
		free_2d(s_numbers);
	}
}
