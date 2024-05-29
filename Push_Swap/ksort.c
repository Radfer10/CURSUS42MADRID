/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:04:31 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 23:28:47 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}


int count_r(t_stack *stack, int index) {
    int count = 0;
    while (stack && stack->index != index) {
        stack = stack->next;
        count++;
    }
    return count;
}

int ft_sqrt(int num) {
    int sqrt = 0;
    while (sqrt * sqrt <= num) {
        sqrt++;
    }
    return sqrt - 1;
}

void assign_indices(t_stack **stack) {
    int size = stack_size(*stack);
    t_stack **array = malloc(size * sizeof(t_stack *));
    t_stack *current = *stack;
    for (int i = 0; i < size; i++) {
        array[i] = current;
        current = current->next;
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i]->content > array[j]->content) {
                t_stack *tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        array[i]->index = i;
    }

    free(array);
}

void insertion_sort(t_stack **stack) {
    t_stack *sorted = NULL;
    while (*stack) {
        t_stack *current = *stack;
        *stack = (*stack)->next;

        if (!sorted || current->content < sorted->content) {
            current->next = sorted;
            sorted = current;
        } else {
            t_stack *temp = sorted;
            while (temp->next && temp->next->content < current->content) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    *stack = sorted;
}


void k_sort1(t_push_swap *push_swap) {
    int i = 0;
    int range = ft_sqrt(push_swap->a_size) * 14 / 10;

    while (push_swap->a != NULL) {
        if (push_swap->a->index <= i) {
            pb(push_swap);
            printf("pb\n");
            rotate(&(push_swap->b));
            printf("rb\n");
            i++;
        } else if (push_swap->a->index <= i + range) {
            pb(push_swap);
            printf("pb\n");
            i++;
        } else {
            rotate(&(push_swap->a));
            printf("ra\n");
        }
    }
}

void k_sort2(t_push_swap *push_swap) {
    int length = stack_size(push_swap->b);
    int rb_count;
    int rrb_count;

    while (length > 0 && push_swap->b != NULL) {
        rb_count = count_r(push_swap->b, length - 1);
        rrb_count = stack_size(push_swap->b) - rb_count;

        if (rb_count <= rrb_count) {
            while (push_swap->b->index != length - 1) {
                rotate(&(push_swap->b));
                printf("rb\n");
            }
        } else {
            while (push_swap->b->index != length - 1) {
                reverse_rotate(&(push_swap->b));
                printf("rrb\n");
            }
        }
        pa(push_swap);
        printf("pa\n");
        length--;
    }
}

void k_sort(t_push_swap *push_swap) {
    assign_indices(&(push_swap->a));
    /*insertion_sort(&(push_swap->a));*/
    k_sort1(push_swap);
    k_sort2(push_swap);
}