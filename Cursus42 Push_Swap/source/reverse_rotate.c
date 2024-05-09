/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:42:36 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/07 21:07:59 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
    last->next = stack;
    prev_to_last->next = 0;
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