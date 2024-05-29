/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:11:09 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 20:28:53 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [numbers...]\n", argv[0]);
        return 1;
    }

    t_push_swap push_swap;
    push_swap.a = NULL;
    push_swap.b = NULL;
    push_swap.a_size = 0;

    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&push_swap.a, value);
    }
    push_swap.a_size = stack_size(push_swap.a);

    printf("Original stack: ");
    print_stack(push_swap.a);

    assign_indices(&(push_swap.a));
    insertion_sort(&(push_swap.a));

    printf("Stack with indices: ");
    t_stack *tmp = push_swap.a;
    while (tmp) {
        printf("%d(%d) ", tmp->content, tmp->index);
        tmp = tmp->next;
    }
    printf("\n");

    // Llamada a push_swap
    push_swap_main(&push_swap);

    printf("Sorted stack: ");
    print_stack(push_swap.a);

    return 0;
}
