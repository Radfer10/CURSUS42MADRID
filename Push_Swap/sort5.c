/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:06:09 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 17:51:43 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int where_small(t_stack *stack, t_stack *min_node) {
    int pos = 1;
    while (stack != NULL) {
        if (stack == min_node) {
            return pos;
        }
        stack = stack->next;
        pos++;
    }
    return -1; // Si no se encuentra el nodo (lo que no debería suceder)
}


void sort_5(t_push_swap *push_swap) {
    if (push_swap == NULL || push_swap->a == NULL)
        return;

    if (is_sorted(push_swap->a))
        return;

    t_stack *min_node = find_min(push_swap->a);
    int i = where_small(push_swap->a, min_node);

    // Mueve el nodo mínimo a la posición adecuada
    if (i == 2) {
        sa(push_swap);
    } else if (i == 3) {
        ra(push_swap);
        sa(push_swap);
    } else if (i == 4) {
        rra(push_swap);
        rra(push_swap);
    } else if (i == 5) {
        rra(push_swap);
        
    }

    // Mueve el nodo mínimo a la pila b
    pb(push_swap);

    // Ordena los 4 elementos restantes
    sort_4(push_swap);

    // Mueve el nodo mínimo de vuelta a la pila a
    pa(push_swap);

    // Asegúrate de que la pila a esté ordenada
    if (push_swap->a->content > push_swap->a->next->content) {
        sa(push_swap);
    }
}


