/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:49:19 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/14 18:41:05 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->a));
	printf("rra\n");
}

void	rrb(t_push_swap *push_swap)
{
	reverse_rotate(&(push_swap->b));
	printf("rrb\n");
}
