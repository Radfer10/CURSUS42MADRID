/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:04:31 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/05 16:21:24 by rde-migu         ###   ########.fr       */
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

/*void simple_sort(t_stack *stack, int length) {
    if (length < 2)
        return;

    t_stack *first = stack;
    t_stack *second = stack->next;
    t_stack *third = second ? second->next : NULL;

    if (length == 2 && first->content > second->content) {
        int temp = first->content;
        first->content = second->content;
        second->content = temp;
        write(1, "sa\n", 3);
    } else if (length == 3) {
        if (first->content > second->content && second->content > third->content) {
            int temp = first->content;
            first->content = second->content;
            second->content = third->content;
            third->content = temp;
            write(1, "sa\n", 3);
            write(1, "ra\n", 3);
        } else if (first->content > second->content && first->content < third->content) {
            int temp = first->content;
            first->content = second->content;
            second->content = temp;
            write(1, "sa\n", 3);
        } else if (first->content < second->content && first->content > third->content) {
            reverse_rotate(&stack);
            write(1, "rra\n", 4);
        } else if (first->content < third->content && second->content > third->content) {
            reverse_rotate(&stack);
            write(1, "rra\n", 4);
            write(1, "sa\n", 3);
        }
    }
}*/


int get_min_index(t_stack *stack) {
    int min_index = stack->index;
    while (stack != NULL) {
        if (stack->index < min_index)
            min_index = stack->index;
        stack = stack->next;
    }
    return min_index;
}

int is_rot_sort(t_stack *stack, int min_s_index) {
    int a, b, c;

    (void)min_s_index;
    a = stack->content;
    b = stack->next->content;
    c = stack->next->next->content;
    if (a < b && b < c)
        return 1;
    if (b < c && a > c)
        return 1;
    if (c < a && a < b)
        return 1;
    return 0;
}

void simple_sort(t_stack *stack, int length) {
    int min_s_index;
    int r;

    if (is_sorted(stack))
        return;
    min_s_index = get_min_index(stack);
    r = count_r(stack, min_s_index);
    if (is_rot_sort(stack, min_s_index)) {
        if (r < length - r)
            rotate(&stack);  // Usamos la versión de rotate sin letras
        else
            reverse_rotate(&stack);  // Usamos la versión de reverse_rotate sin letras
    } else {
        swap(&stack);  // Usamos la versión de swap sin letras
        if (is_sorted(stack))
            return;
        if (r < length - r)
            rotate(&stack);
        else
            reverse_rotate(&stack);
    }
}


void s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length) {
    int min_index;
    int iter;
    int n;

    iter = 0;
    n = length;
    while (iter++ < n - 3) {
        min_index = get_min_index(stack_a);
        if (count_r(stack_a, min_index) <= n - min_index - count_r(stack_a, min_index))
            while (stack_a->content != min_index)
                rotate(&stack_a);  // Usamos la versión de rotate sin letras
        else
            while (stack_a->content != min_index)
                reverse_rotate(&stack_a);  // Usamos la versión de reverse_rotate sin letras
        if (is_sorted(stack_a) && stack_b == NULL)
            return;
        push(&stack_b, &stack_a);  // Usamos la versión de push sin letras
        length--;
    }
    simple_sort(stack_a, length);
    iter = 0;
    while (iter++ < n - 3)
        push(&stack_a, &stack_b);
}
void k_sort1(t_stack *stack_a, t_stack *stack_b, int length) {
    int i;
    int range;

    i = 0;
    range = ft_sqrt(length) * 14 / 10;
    while (stack_a) {
        if (stack_a->index <= i) {
            push(&stack_b, &stack_a);  // Usamos la versión de push sin letras
            rotate(&stack_b);  // Usamos la versión de rotate sin letras
            i++;
        } else if (stack_a->index <= i + range) {
            push(&stack_b, &stack_a);
            i++;
        } else
            rotate(&stack_a);  // Usamos la versión de rotate sin letras
    }
}

void k_sort2(t_stack **stack_a, t_stack **stack_b, int length) {
    int rb_count;
    int rrb_count;

    if (stack_a == NULL || stack_b == NULL || *stack_a == NULL || *stack_b == NULL) {
        // Manejar el caso de punteros nulos
        return;
    }

    while (length - 1 >= 0) {
        rb_count = count_r(*stack_b, length - 1);
        rrb_count = (length + 3) - rb_count;
        if (rb_count <= rrb_count) {
            while ((*stack_b)->index != length - 1)
                rotate(stack_b);
            push(stack_a, stack_b);
            length--;
        } else {
            while ((*stack_b)->index != length - 1)
                reverse_rotate(stack_b);
            push(stack_a, stack_b);
            length--;
        }
    }
}





void k_sort(t_push_swap *push_swap) {
    assign_indices(&(push_swap->a));
    k_sort1(push_swap->a, push_swap->b, push_swap->a_size);
    k_sort2(&(push_swap->a), &(push_swap->b), push_swap->a_size);
    s_insertion_sort(push_swap->a, push_swap->b, push_swap->a_size);
}