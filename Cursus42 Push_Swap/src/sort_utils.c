/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:07:52 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 17:01:48 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack != NULL)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	count_r(t_stack *stack, int index)
{
	int	count;

	count = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	ft_sqrt(int num)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt <= num)
	{
		sqrt++;
	}
	return (sqrt - 1);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
