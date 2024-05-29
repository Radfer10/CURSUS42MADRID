/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:46 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 20:05:48 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_3(t_push_swap *push_swap)
{
    if (push_swap->a != NULL)
    {
        t_stack *first_node;
        t_stack *second_node;
        t_stack *third_node;

		if (is_sorted(push_swap->a))
			return;

        first_node = push_swap->a;
        second_node = push_swap->a->next;
        third_node = push_swap->a->next->next;

        if (first_node->content > second_node->content && first_node->content > third_node->content)
            ra(push_swap);
        else if (second_node->content > first_node->content && second_node->content > third_node->content)
            rra(push_swap);
        
        if (push_swap->a->content > push_swap->a->next->content)
            sa(push_swap);
    }
}