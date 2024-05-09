/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:52:11 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/06 21:20:00 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *swap(t_stack *stack)
{
    t_stack *tmp;

    if (!stack || (stack)->next == 0)
        return stack;
    tmp = stack->next;
    stack->next = tmp->next;
    tmp->next = stack;
    return (tmp);
} 

void    sa(t_stack *stack_a)
{
    swap(stack_a);
}

void    sb(t_stack *stack_b)
{
    swap(stack_b);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
}
