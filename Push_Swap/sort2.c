/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:29 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 17:34:01 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_2(t_push_swap *push_swap)
{
    if (push_swap->a != NULL)
    {
        t_stack *node;

        node = push_swap->a;
        if (node->next != NULL)
        {
            // Compara los elementos y realiza el intercambio si es necesario
            if (node->content > node->next->content)
                sa(push_swap);
                
        }
    }
}
