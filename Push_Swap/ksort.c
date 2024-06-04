/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:04:31 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/04 22:30:43 by rde-migu         ###   ########.fr       */
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


/*int get_min_index(t_stack *stack) {
    int min_index = stack->index;
    while (stack != NULL) {
        if (stack->index < min_index)
            min_index = stack->index;
        stack = stack->next;
    }
    return min_index;
}*/



/*void s_insertion_sort(t_push_swap *push_swap, int length) {
    int min_index;
    int iter = 0;
    int n = length;

    while (iter++ < n - 3) {
        min_index = get_min_index(push_swap->a);

        if (count_r(push_swap->a, min_index) <= n - min_index - count_r(push_swap->a, min_index)) {
            while (push_swap->a->index != min_index) {
                rotate(&(push_swap->a));
                write(1, "ra\n", 3);
            }
        } else {
            while (push_swap->a->index != min_index) {
                reverse_rotate(&(push_swap->a));
                write(1, "rra\n", 4);
            }
        }

        push(&(push_swap->b), &(push_swap->a));
        write(1, "pb\n", 3);
        length--;
    }

    simple_sort(push_swap->a, length);

    iter = 0;
    while (iter++ < n - 3) {
        push(&(push_swap->a), &(push_swap->b));
        write(1, "pa\n", 3);
    }
}*/

void k_sort1(t_push_swap *push_swap) {
    int i = 0;
    int range = ft_sqrt(push_swap->a_size) * 14 / 10;

    while (push_swap->a != NULL) {
        if (push_swap->a->index <= i) {
            pb(push_swap);
            write(1, "pb\n", 3);
            rotate(&(push_swap->b));
            write(1, "rb\n", 3);
            i++;
        } else if (push_swap->a->index <= i + range) {
            pb(push_swap);
            write(1, "pb\n", 3);
            i++;
        } else {
            rotate(&(push_swap->a));
            write(1, "ra\n", 3);
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
                write(1, "rb\n", 3);
            }
        } else {
            while (push_swap->b->index != length - 1) {
                reverse_rotate(&(push_swap->b));
                write(1, "rrb\n", 4);
            }
        }
        pa(push_swap);
        write(1, "pa\n", 3);
        length--;
    }
}

void k_sort(t_push_swap *push_swap) {
    assign_indices(&(push_swap->a));
    k_sort1(push_swap);
    k_sort2(push_swap);
}