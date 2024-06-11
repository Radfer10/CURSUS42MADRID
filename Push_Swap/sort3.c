/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:46 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 19:02:55 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// Asegúrate de que hay al menos 3 nodos
	if (second_node == NULL || third_node == NULL)
		return ;
	// Caso 1: 321
	if (first_node->content > second_node->content
		&& second_node->content > third_node->content)
	{
		sa(push_swap);
		rra(push_swap);
	}
	// Caso 2: 312
	else if (first_node->content > third_node->content
		&& third_node->content > second_node->content)
	{
		ra(push_swap);
	}
	// Caso 3: 213
	else if (second_node->content > first_node->content
		&& first_node->content > third_node->content)
	{
		rra(push_swap);
	}
	// Caso 4: 231
	else if (second_node->content > third_node->content
		&& third_node->content > first_node->content)
	{
		sa(push_swap);
		ra(push_swap);
	}
	// Caso 5: 132
	else if (third_node->content > first_node->content
		&& first_node->content > second_node->content)
	{
		sa(push_swap);
	}
}
