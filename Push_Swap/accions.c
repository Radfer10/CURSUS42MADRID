/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 17:38:15 by rde-migu         ###   ########.fr       */
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
    printf("sa\n");
}

void	sb(t_push_swap *push_swap)
{
	push_swap->b = swap(push_swap->b);
    printf("sb\n");
}

void	ss(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	push_swap->b = swap(push_swap->b);
    printf("ss\n");
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

void pa(t_push_swap *push_swap) {
    t_stack *tmp;

    if (push_swap->b == NULL) return;

    tmp = push_swap->b;
    push_swap->b = push_swap->b->next;
    tmp->next = push_swap->a;
    push_swap->a = tmp;
    printf("pa\n");
}

void pb(t_push_swap *push_swap) {
    t_stack *tmp;

    if (push_swap->a == NULL) return;

    tmp = push_swap->a;
    push_swap->a = push_swap->a->next;
    tmp->next = push_swap->b;
    push_swap->b = tmp;
    printf("pb\n");
}

void rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;

    t_stack *first = *stack;
    t_stack *last = *stack;

    while (last->next) {
        last = last->next;
    }

    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void ra(t_push_swap *push_swap) {
    rotate(&(push_swap->a));
    printf("ra\n");
}

void rb(t_push_swap *push_swap) {
    rotate(&(push_swap->b));
    printf("rb\n");
}

void rr(t_push_swap *push_swap) {
    rotate(&(push_swap->a));
    rotate(&(push_swap->b));
    printf("rr\n");
}

void reverse_rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;

    t_stack *prev = NULL;
    t_stack *current = *stack;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

void	rra(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->a));
    printf("rra\n");
}

void	rrb(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->b));
    printf("rrb\n");
}

void	rrr(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->a));
	reverse_rotate(&(push_swap->b));
    printf("rrr\n");
}