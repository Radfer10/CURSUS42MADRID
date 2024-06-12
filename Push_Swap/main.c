/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:11:09 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/11 18:43:40 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void free_stack(t_stack **stack) {
    t_stack *temp;
    while (*stack) {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    t_push_swap push_swap;
    push_swap.a = NULL;
    push_swap.b = NULL;
    push_swap.a_size = 0;

    arg_parse(&push_swap, argc, argv);
    assign_indices(&(push_swap.a));
    t_stack *tmp = push_swap.a;
    while (tmp) {
        tmp = tmp->next;
    }
    push_swap_main(&push_swap);
    free_stack(&push_swap.a);
    free_stack(&push_swap.b);
    return 0;
}


