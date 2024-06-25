/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:47:42 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/18 01:58:52 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_push_swap *push_swap)
{
	t_stack	*tmp;

	if (push_swap->b == NULL)
		return ;
	tmp = push_swap->b;
	push_swap->b = push_swap->b->next;
	tmp->next = push_swap->a;
	push_swap->a = tmp;
	ft_printf("pa\n");
}

void	pb(t_push_swap *push_swap)
{
	t_stack	*tmp;

	if (push_swap->a == NULL)
		return ;
	tmp = push_swap->a;
	push_swap->a = push_swap->a->next;
	tmp->next = push_swap->b;
	push_swap->b = tmp;
	ft_printf("pb\n");
}
