/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 20:03:19 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *swap(t_stack *stack)
{
    t_stack *tmp;

    if (!stack || stack->next == NULL)
        return stack;
    tmp = stack->next;
    stack->next = tmp->next;
    tmp->next = stack;
    return tmp;
}


void	sa(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
}

void	sb(t_push_swap *push_swap)
{
	push_swap->b = swap(push_swap->b);
}

void	ss(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	push_swap->b = swap(push_swap->b);
}

void push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (*stack_b == 0)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void	pa(t_push_swap *push_swap)
{
	push(&push_swap->a, &push_swap->b);
}

void	pb(t_push_swap *push_swap)
{
	push(&push_swap->b, &push_swap->a);
}

t_stack *rotate(t_stack *stack)
{
    if (!stack || !stack->next)
        return stack; 
    
    t_stack *first = stack;
    t_stack *second = stack->next;
    t_stack *last = stack;
    
	while (last->next)
    {
        last = last->next;
    }
	last->next = first;
    stack = second;
    first->next = NULL;
	return stack;
}


void	ra(t_push_swap *push_swap)
{
	push_swap->a = rotate(push_swap->a);
}

void	rb(t_push_swap *push_swap)
{
	push_swap->b = rotate(push_swap->b);
}

void	rr(t_push_swap *push_swap)
{
	push_swap->a = rotate(push_swap->a);
	push_swap->b = rotate(push_swap->b);
}

t_stack *reverse_rotate(t_stack *stack)
{
    if (!stack || !stack->next)
        return stack; 
    t_stack *last = stack;
    t_stack *prev_to_last = 0;
    while (last->next)
    {
		
        prev_to_last = last;
		last = last->next;
        
    }
	prev_to_last->next = 0;
    last->next = stack;
	return last;
}

void	rra(t_push_swap *push_swap)
{
	push_swap->a = reverse_rotate(push_swap->a);
}

void	rrb(t_push_swap *push_swap)
{
	push_swap->b = reverse_rotate(push_swap->b);
}

void	rrr(t_push_swap *push_swap)
{
	push_swap->a = reverse_rotate(push_swap->a);
	push_swap->b = reverse_rotate(push_swap->b);
}