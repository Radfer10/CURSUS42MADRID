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

int find_max(t_stack *stack) {
    int max = INT_MIN;
    while (stack != NULL) {
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
    }
    return max;
}

int num_bits(int num) {
    int bits = 0;
    while (num > 0) {
        bits++;
        num >>= 1;
    }
    return bits;
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

int is_sorted(t_stack *stack) {
    while (stack && stack->next) {
        if (stack->content > stack->next->content) return 0;
        stack = stack->next;
    }
    return 1;
}

int get_min_index(t_stack *stack) {
    int min_index = stack->index;
    while (stack) {
        if (stack->index < min_index) min_index = stack->index;
        stack = stack->next;
    }
    return min_index;
}

void bubblesort(t_stack **stack) {
    t_stack *comparer = *stack;
    while (comparer != NULL) {
        t_stack *compared = *stack;
        int i = 1;
        while (compared != NULL) {
            if (comparer->content > compared->content)
                i++;
            compared = compared->next;
        }
        comparer->index = i;
        comparer = comparer->next;
    }
}

static int max_number_of_bits(t_stack *stack) {
    t_stack *node = stack;
    unsigned int max = node->index;
    int number_of_bits = 0;

    while (node) {
        if (node->index > max)
            max = node->index;
        node = node->next;
    }

    while ((max >> number_of_bits) != 0)
        number_of_bits++;

    return number_of_bits;
}

void sorter(t_push_swap *push_swap) {
    t_stack *head_a;
    int bit_position;
    int j;
    int number_of_nodes;
    int number_of_bits;

    bit_position = 0;
    number_of_nodes = stack_size(push_swap->a);
    number_of_bits = max_number_of_bits(push_swap->a);
    while (bit_position < number_of_bits) {
        j = 0;
        while (j++ < number_of_nodes) {
            head_a = push_swap->a;
            if (((head_a->index >> bit_position) & 1) == 1) {
                rotate(&(push_swap->a));
                printf("ra\n");
            } else {
                pb(push_swap);
                printf("pb\n");
            }
        }
        while (push_swap->b != NULL)
            pa(push_swap);
        bit_position++;
        printf("pa\n");
    }
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
    int length = push_swap->a_size;
    int rb_count;
    int rrb_count;

    while (length - 1 >= 0) {
        rb_count = count_r(push_swap->b, length - 1);
        rrb_count = (length + 3) - rb_count;
        if (rb_count <= rrb_count) {
            while (push_swap->b->index != length - 1) {
                rotate(&(push_swap->b));
                printf("rb\n");
            }
            pa(push_swap);
            printf("pa\n");
            length--;
        } else {
            while (push_swap->b->index != length - 1) {
                reverse_rotate(&(push_swap->b));
                printf("rrb\n");
            }
            pa(push_swap);
            printf("pa\n");
            length--;
        }
    }
}

// Función para agregar elementos a la pila
void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->content = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Función para imprimir la pila
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

    // Crear la estructura push_swap y inicializar las pilas
    t_push_swap push_swap;
    push_swap.a = NULL;
    push_swap.b = NULL;
    push_swap.a_size = 0;

    // Añadir elementos a la pila a desde los argumentos de la línea de comandos
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&push_swap.a, value);
    }
    push_swap.a_size = stack_size(push_swap.a);

    printf("Pila original: ");
    print_stack(push_swap.a);

    bubblesort(&push_swap.a);

    // Ordenar la pila usando K-Sort
    k_sort1(&push_swap);
    k_sort2(&push_swap);

    printf("Pila ordenada: ");
    print_stack(push_swap.a);

    return 0;
}

