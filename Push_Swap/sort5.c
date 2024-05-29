/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:06:09 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 20:06:19 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5(t_push_swap *push_swap) {
    if (push_swap == NULL || push_swap->a == NULL)
        return;

    if (is_sorted(push_swap->a))
        return;

    t_stack *min_node = find_min(push_swap->a);

    // Mueve el nodo mínimo a la pila b
    while (push_swap->a != min_node) {
        ra(push_swap);
        printf("ra\n");
    }
    pb(push_swap);
    printf("pb\n");

    // Ordena los 4 elementos restantes
    sort_4(push_swap);

    // Mueve el nodo mínimo de vuelta a la pila a
    pa(push_swap);
    printf("pa\n");

    // Asegúrate de que la pila a esté ordenada
    if (push_swap->a->content > push_swap->a->next->content) {
        sa(push_swap);
        printf("sa\n");
    }
}