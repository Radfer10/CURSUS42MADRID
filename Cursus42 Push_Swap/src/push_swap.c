/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:06:52 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/18 03:49:04 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	k_sort(t_push_swap *push_swap)
{
	assign_indices(&(push_swap->a));
	k_sort1(push_swap);
	k_sort2(push_swap);
}

void	push_swap_main(t_push_swap *push_swap)
{
	int	size;

	if (is_sorted(push_swap->a))
		return ;
	size = stack_size(push_swap->a);
	if (size == 2)
		sort_2(push_swap);
	else if (size == 3)
		sort_3(push_swap);
	else if (size == 4)
		sort_4(push_swap);
	else if (size == 5)
		sort_5(push_swap);
	else
		k_sort(push_swap);
}
