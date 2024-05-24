#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack {
    int content;
    unsigned int index;
    struct s_stack *next;
} t_stack;

typedef struct s_push_swap {
    t_stack *a;
    t_stack *b;
    int a_size;
} t_push_swap;

int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

void pb(t_push_swap *push_swap) {
    t_stack *tmp;
    if (push_swap->a) {
        tmp = push_swap->a;
        push_swap->a = push_swap->a->next;
        tmp->next = push_swap->b;
        push_swap->b = tmp;
        push_swap->a_size--;
    }
}

void pa(t_push_swap *push_swap) {
    t_stack *tmp;
    if (push_swap->b) {
        tmp = push_swap->b;
        push_swap->b = push_swap->b->next;
        tmp->next = push_swap->a;
        push_swap->a = tmp;
        push_swap->a_size++;
    }
}

void rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    t_stack *temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;
    t_stack *current = *stack;
    while (current->next) {
        current = current->next;
    }
    current->next = temp;
}

void reverse_rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    t_stack *second_last = NULL;
    t_stack *last = *stack;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void swap(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    t_stack *first = *stack;
    t_stack *second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
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

void bubblesort(t_stack **stack) {
    t_stack *comparer = *stack;
    while (comparer != NULL) {
        t_stack *compared = *stack;
        int i = 0;
        while (compared != NULL) {
            if (comparer->content > compared->content)
                i++;
            compared = compared->next;
        }
        comparer->index = i;
        comparer = comparer->next;
    }
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

    while (length > 0) {
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

void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->content = value;
    new_node->next = *stack;
    *stack = new_node;
}

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

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

    printf("Pila original: ");
    print_stack(push_swap.a);

    bubblesort(&push_swap.a);

    k_sort1(&push_swap);
    k_sort2(&push_swap);

    printf("Pila ordenada: ");
    print_stack(push_swap.a);

    return 0;
}





