/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:06:09 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 18:18:10 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	where_small(t_stack *stack, t_stack *min_node)
{
	int	pos;

	pos = 1;
	while (stack != NULL)
	{
		if (stack == min_node)
		{
			return (pos);
		}
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	special_cases_5(t_push_swap *push_swap, int position)
{
	if (position == 2)
	{
		sa(push_swap);
	}
	else if (position == 3)
	{
		ra(push_swap);
		sa(push_swap);
	}
	else if (position == 4)
	{
		rra(push_swap);
		rra(push_swap);
	}
	else if (position == 5)
	{
		rra(push_swap);
	}
}

void	sort_stack_5(t_push_swap *push_swap)
{
	pb(push_swap);
	sort_4(push_swap);
	pa(push_swap);
	if (push_swap->a->content > push_swap->a->next->content)
	{
		sa(push_swap);
	}
}

void	sort_5(t_push_swap *push_swap)
{
	t_stack	*min_node;
	int		position;

	if (push_swap == NULL || push_swap->a == NULL)
		return ;
	if (is_sorted(push_swap->a))
		return ;
	min_node = find_min(push_swap->a);
	position = where_small(push_swap->a, min_node);
	special_cases_5(push_swap, position);
	sort_stack_5(push_swap);
}
