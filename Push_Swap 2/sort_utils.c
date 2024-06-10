/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:07:52 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 23:41:44 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}*/

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}
void push2(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->content = value;
    new_node->next = *stack;
    *stack = new_node;
}

t_stack *find_min(t_stack *stack)
{
	t_stack *min = stack;
	while (stack != NULL)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return min;
}
