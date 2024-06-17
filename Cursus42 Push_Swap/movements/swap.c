/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:46:59 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/17 19:13:08 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	ft_printf("sa\n");
}

void	sb(t_push_swap *push_swap)
{
	push_swap->b = swap(push_swap->b);
	ft_printf("sb\n");
}

void	ss(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	push_swap->b = swap(push_swap->b);
	ft_printf("ss\n");
}
