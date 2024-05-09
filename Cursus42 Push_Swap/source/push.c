/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:00:13 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/07 20:14:53 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (*stack_b = 0)
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
	push(&push_swap->a, &push_swap->b);
}

