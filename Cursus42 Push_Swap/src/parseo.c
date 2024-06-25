/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:39 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/24 19:01:13 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_to_stack(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		ft_putstr_fd("Memory allocation error\n", 2);
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

void	add_numbers_to_stack(t_push_swap *ps, char **s_numbers)
{
	int	num;
	int	k;

	k = 0;
	while (s_numbers[k])
	{
		if (contains_invalid_signs(s_numbers[k])
			|| contains_non_numeric_characters(s_numbers[k]))
		{
			free_stack(&ps->a);
			display_error("Error", 1);
		}
		num = ft_atoi(s_numbers[k]);
		if (contains_duplicate(ps->a, num))
		{
			free_stack(&ps->a);
			display_error("Error", 1);
		}
		add_to_stack(&ps->a, num);
		ps->a_size++;
		k++;
	}
}

void	parse_arguments(t_push_swap *ps, int argc, char **argv)
{
	char	**s_numbers;
	int		i;

	i = 1;
	while (i < argc)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
		{
			free_stack(&ps->a);
			display_error("Error", 1);
		}
		check_range(s_numbers, &ps->a);
		add_numbers_to_stack(ps, s_numbers);
		free_2d(s_numbers);
		i++;
	}
}

void	arg_parse(t_push_swap *ps, int argc, char **argv)
{
	parse_arguments(ps, argc, argv);
}
