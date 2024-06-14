/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:52 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 18:11:52 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4(t_push_swap *push_swap)
{
	t_stack	*min_node;

	if (is_sorted(push_swap->a))
		return ;
	min_node = find_min(push_swap->a);
	while (push_swap->a != min_node)
	{
		ra(push_swap);
	}
	pb(push_swap);
	sort_3(push_swap);
	pa(push_swap);
}
