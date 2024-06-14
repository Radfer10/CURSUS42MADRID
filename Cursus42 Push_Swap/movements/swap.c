/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:46:59 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 18:40:59 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	printf("sa\n");
}

void	sb(t_push_swap *push_swap)
{
	push_swap->b = swap(push_swap->b);
	printf("sb\n");
}

void	ss(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	push_swap->b = swap(push_swap->b);
	printf("ss\n");
}
