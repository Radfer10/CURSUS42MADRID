/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:29 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 19:02:48 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_push_swap *push_swap)
{
		t_stack *node;

	if (push_swap->a != NULL)
	{
		node = push_swap->a;
		if (node->next != NULL)
		{
			// Compara los elementos y realiza el intercambio si es necesario
			if (node->content > node->next->content)
				sa(push_swap);
		}
	}
}
