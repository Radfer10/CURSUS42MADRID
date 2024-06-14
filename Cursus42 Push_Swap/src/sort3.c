/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:46 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 18:26:01 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	compare_and_swap_3(t_push_swap *push_swap, t_stack *first,
		t_stack *second, t_stack *third)
{
	if (first->content > second->content && second->content > third->content)
	{
		sa(push_swap);
		rra(push_swap);
	}
	else if (first->content > third->content
		&& third->content > second->content)
		ra(push_swap);
	else if (second->content > first->content
		&& first->content > third->content)
		rra(push_swap);
	else if (second->content > third->content
		&& third->content > first->content)
	{
		sa(push_swap);
		ra(push_swap);
	}
	else if (third->content > first->content
		&& first->content > second->content)
		sa(push_swap);
}

void	sort_3(t_push_swap *push_swap)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	if (push_swap == NULL || push_swap->a == NULL)
		return ;
	if (is_sorted(push_swap->a))
		return ;
	first_node = push_swap->a;
	second_node = push_swap->a->next;
	third_node = push_swap->a->next->next;
	if (second_node == NULL || third_node == NULL)
		return ;
	compare_and_swap_3(push_swap, first_node, second_node, third_node);
}
