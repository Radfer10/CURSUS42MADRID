/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:48:38 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/18 01:59:06 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_push_swap *push_swap)
{
	rotate(&(push_swap->a));
	ft_printf("ra\n");
}

void	rb(t_push_swap *push_swap)
{
	rotate(&(push_swap->b));
	ft_printf("rb\n");
}

void	rr(t_push_swap *push_swap)
{
	rotate(&(push_swap->a));
	rotate(&(push_swap->b));
	ft_printf("rr\n");
}
