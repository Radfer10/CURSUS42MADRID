/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/05 16:04:53 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_stack *first = *stack;
    t_stack *second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void sa(t_push_swap *push_swap) {
    swap(&(push_swap->a)); // Modifica directamente la pila 'a'
}

void sb(t_push_swap *push_swap) {
    swap(&(push_swap->b)); // Modifica directamente la pila 'b'
}

void ss(t_push_swap *push_swap) {
    swap(&(push_swap->a)); // Modifica directamente la pila 'a'
    swap(&(push_swap->b)); // Modifica directamente la pila 'b'
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
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_stack *first = *stack;
    t_stack *last = *stack;
    while (last->next != NULL)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
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