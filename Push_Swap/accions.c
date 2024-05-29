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

#include "push_swap.h"

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

void rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    t_stack *temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;
    t_stack *current = *stack;
    while (current->next) {
        current = current->next;
    }
    current->next = temp;
}

void ra(t_push_swap *push_swap) {
    rotate(&(push_swap->a));
}

void rb(t_push_swap *push_swap) {
    rotate(&(push_swap->b));
}

void rr(t_push_swap *push_swap) {
    rotate(&(push_swap->a));
    rotate(&(push_swap->b));
}

void reverse_rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    t_stack *second_last = NULL;
    t_stack *last = *stack;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void	rra(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->a));
}

void	rrb(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->b));
}

void	rrr(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->a));
	reverse_rotate(&(push_swap->b));
}