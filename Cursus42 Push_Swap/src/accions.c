/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 18:08:40 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack || stack->next == NULL)
		return (stack);
	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	return (tmp);
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == 0)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}
