/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:49:19 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/18 01:58:46 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->a));
	ft_printf("rra\n");
}

void	rrb(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->b));
	ft_printf("rrb\n");
}
