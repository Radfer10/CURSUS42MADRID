/*#include <stdio.h>
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

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node) {
        printf("Error: Memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    new_node->content = value;
    new_node->next = *stack;
    *stack = new_node;
}





void pb(t_push_swap *push_swap) {
    if (push_swap->a) {
        t_stack *tmp = push_swap->a;
        push_swap->a = push_swap->a->next;
        tmp->next = push_swap->b;
        push_swap->b = tmp;
        push_swap->a_size--; // Actualizar el tamaño de la pila a
        printf("pb\n");
    }
}

void pa(t_push_swap *push_swap) {
    if (push_swap->b) {
        t_stack *tmp = push_swap->b;
        push_swap->b = push_swap->b->next;
        tmp->next = push_swap->a;
        push_swap->a = tmp;
        push_swap->a_size++; // Actualizar el tamaño de la pila a
        printf("pa\n");
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

void sa(t_push_swap *push_swap) {
    swap(&(push_swap->a));
    printf("sa\n");
}

void sb(t_push_swap *push_swap) {
    swap(&(push_swap->b));
    printf("sb\n");
}

void ra(t_push_swap *push_swap) {
    rotate(&(push_swap->a));
    printf("ra\n");
}

void rb(t_push_swap *push_swap) {
    rotate(&(push_swap->b));
    printf("rb\n");
}

void rra(t_push_swap *push_swap) {
    reverse_rotate(&(push_swap->a));
    printf("rra\n");
}

void rrb(t_push_swap *push_swap) {
    reverse_rotate(&(push_swap->b));
    printf("rrb\n");
}

void insertion_sort(t_stack **stack) {
    t_stack *sorted = NULL;
    while (*stack != NULL) {
        int value = (*stack)->content;
        t_stack *current = sorted;
        t_stack *prev = NULL;
        while (current != NULL && current->content < value) {
            prev = current;
            current = current->next;
        }
        t_stack *new_node = malloc(sizeof(t_stack));
        if (!new_node) {
            printf("Error: Memoria insuficiente\n");
            exit(EXIT_FAILURE);
        }
        new_node->content = value;
        if (prev == NULL) {
            new_node->next = sorted;
            sorted = new_node;
        } else {
            prev->next = new_node;
            new_node->next = current;
        }
        *stack = (*stack)->next;
    }
    *stack = sorted;
}

void index_stack(t_stack **stack) {
    insertion_sort(stack);

    int index = 0;
    t_stack *current = *stack;
    while (current != NULL) {
        current->index = index++;
        current = current->next;
    }
}

void k_sort1(t_push_swap *push_swap) {
    int i = 0;
    int range = stack_size(push_swap->a) / 5;
    while (push_swap->a != NULL && push_swap->a_size > 0) {
        printf("K_SORT1: i = %d, range = %d\n", i, range);
        if (push_swap->a->index <= i) {
            pb(push_swap);
            rb(push_swap);
            i++;
        } else if (push_swap->a->index <= i + range) {
            pb(push_swap);
            i++;
        } else {
            ra(push_swap);
        }
        printf("Pila A después de movimiento en k_sort1: ");
        print_stack(push_swap->a);
    }
}

void k_sort2(t_push_swap *push_swap) {
    while (push_swap->b != NULL && push_swap->b->next != NULL) {
        int max_index = -1;
        t_stack *current = push_swap->b;
        while (current) {
            if (current->index > max_index) {
                max_index = current->index;
            }
            current = current->next;
        }
        current = push_swap->b;
        int count = 0;
        while (current && current->index != max_index) {
            count++;
            current = current->next;
        }
        if (count <= stack_size(push_swap->b) / 2) {
            while (push_swap->b != NULL && push_swap->b->index != max_index) {
                rb(push_swap);
            }
        } else {
            while (push_swap->b != NULL && push_swap->b->index != max_index) {
                rrb(push_swap);
            }
        }
        if (push_swap->b != NULL) {
            pa(push_swap);
        }
        printf("Pila B después de movimiento en k_sort2: ");
        print_stack(push_swap->b);
    }
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

    index_stack(&push_swap.a);

    k_sort1(&push_swap);

    printf("Pila después de k_sort1: ");
    print_stack(push_swap.a);
    print_stack(push_swap.b);

    k_sort2(&push_swap);

    printf("Pila ordenada: ");
    print_stack(push_swap.a);

    return 0;
}*/




/*#include <stdio.h>
#include <stdlib.h>

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
    int *index_array = malloc(length * sizeof(int));

    // Almacenar los índices de los elementos en un array auxiliar
    t_stack *current = push_swap->b;
    for (int i = 0; i < length; i++) {
        index_array[i] = current->index;
        current = current->next;
    }

    // Variable para seguir la cantidad de movimientos realizados
    int moves = 0;

    while (length > 0 && push_swap->b != NULL) {
        int rb_count = count_r(push_swap->b, length - 1);
        int rrb_count = length - rb_count;

        // Optimizar las rotaciones
        if (rb_count <= rrb_count) {
            while (index_array[0] != length - 1) {
                rotate(&(push_swap->b));
                printf("rb\n");
                moves++;
                if (moves > length) {
                    // Si los movimientos exceden la longitud de la pila, salimos del bucle
                    free(index_array);
                    return;
                }
            }
        } else {
            while (index_array[0] != length - 1) {
                reverse_rotate(&(push_swap->b));
                printf("rrb\n");
                moves++;
                if (moves > length) {
                    // Si los movimientos exceden la longitud de la pila, salimos del bucle
                    free(index_array);
                    return;
                }
            }
        }
        
        // Simplificar la lógica de decisión
        if (index_array[0] != length - 1) {
            pa(push_swap);
            printf("pa\n");
        }

        // Actualizar el array de índices
        for (int i = 0; i < length - 1; i++) {
            index_array[i] = index_array[i + 1];
        }
        
        length--;
    }

    free(index_array);
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

    printf("Original stack: ");
    print_stack(push_swap.a);

    assign_indices(&(push_swap.a));

    printf("Stack with indices: ");
    t_stack *tmp = push_swap.a;
    while (tmp) {
        printf("%d(%d) ", tmp->content, tmp->index);
        tmp = tmp->next;
    }
    printf("\n");

    k_sort1(&push_swap);
    k_sort2(&push_swap);

    printf("Sorted stack: ");
    print_stack(push_swap.a);

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int content;
    struct s_stack *next;
} t_stack;

typedef struct s_push_swap {
    t_stack *a;
    t_stack *b;
} t_push_swap;

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

int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

int partition(t_stack **array, int low, int high) {
    int pivot = array[high]->content;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j]->content <= pivot) {
            i++;
            t_stack *temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    t_stack *temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quick_sort(t_stack **array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void sort_and_apply_moves(t_push_swap *push_swap) {
    int size = stack_size(push_swap->a);
    t_stack **array = malloc(size * sizeof(t_stack *));
    t_stack *current = push_swap->a;
    for (int i = 0; i < size; i++) {
        array[i] = current;
        current = current->next;
    }

    quick_sort(array, 0, size - 1);

    for (int i = size - 1; i >= 0; i--) {
        push_swap->a = array[i];
        while (push_swap->a != array[i]) {
            if (array[i]->next == push_swap->a) {
                push_swap->a = array[i];
                break;
            }
            array[i] = array[i]->next;
        }
        printf("pb\n");
        push(&(push_swap->b), array[i]->content);
    }

    free(array);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [numbers...]\n", argv[0]);
        return 1;
    }

    t_push_swap push_swap;
    push_swap.a = NULL;
    push_swap.b = NULL;

    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&(push_swap.a), value);
    }

    printf("Original stack A: ");
    print_stack(push_swap.a);

    sort_and_apply_moves(&push_swap);

    printf("Sorted stack B: ");
    print_stack(push_swap.b);

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int content;
    unsigned int index;
    struct s_stack *next;
} t_stack;

typedef struct s_push_swap {
    t_stack *a;
    t_stack *b;
} t_push_swap;

void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node) {
        printf("Error: Memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
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

void swap(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    int temp = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = temp;
}

void rotate(t_stack **stack) {
    if (!*stack || !(*stack)->next) return;
    t_stack *first = *stack;
    t_stack *last = *stack;
    *stack = (*stack)->next;
    first->next = NULL;

    while (last->next) {
        last = last->next;
    }
    last->next = first;
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

void sa(t_push_swap *push_swap) {
    swap(&(push_swap->a));
    printf("sa\n");
}

void sb(t_push_swap *push_swap) {
    swap(&(push_swap->b));
    printf("sb\n");
}

void pa(t_push_swap *push_swap) {
    if (!push_swap->b) return;
    t_stack *tmp = push_swap->b;
    push_swap->b = push_swap->b->next;
    tmp->next = push_swap->a;
    push_swap->a = tmp;
    printf("pa\n");
}

void pb(t_push_swap *push_swap) {
    if (!push_swap->a) return;
    t_stack *tmp = push_swap->a;
    push_swap->a = push_swap->a->next;
    tmp->next = push_swap->b;
    push_swap->b = tmp;
    printf("pb\n");
}

void ra(t_push_swap *push_swap) {
    rotate(&(push_swap->a));
    printf("ra\n");
}

void rb(t_push_swap *push_swap) {
    rotate(&(push_swap->b));
    printf("rb\n");
}

void rra(t_push_swap *push_swap) {
    reverse_rotate(&(push_swap->a));
    printf("rra\n");
}

void rrb(t_push_swap *push_swap) {
    reverse_rotate(&(push_swap->b));
    printf("rrb\n");
}

int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

void index_stack(t_stack *stack) {
    int size = stack_size(stack);
    int *arr = malloc(size * sizeof(int));
    t_stack *current = stack;
    for (int i = 0; i < size; i++) {
        arr[i] = current->content;
        current = current->next;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    current = stack;
    for (int i = 0; i < size; i++) {
        current->index = 0;
        for (int j = 0; j < size; j++) {
            if (current->content == arr[j]) {
                current->index = j;
                break;
            }
        }
        current = current->next;
    }
    free(arr);
}

void k_sort1(t_push_swap *push_swap) {
    int i = 0;
    int range = stack_size(push_swap->a) / 5;
    while (push_swap->a != NULL) {
        if (push_swap->a->index <= i) {
            pb(push_swap);
            rb(push_swap);
            i++;
        } else if (push_swap->a->index <= i + range) {
            pb(push_swap);
            i++;
        } else {
            ra(push_swap);
        }
    }
}

void k_sort2(t_push_swap *push_swap) {
    while (push_swap->b != NULL) {
        int max_index = -1;
        t_stack *current = push_swap->b;
        while (current) {
            if (current->index > max_index) {
                max_index = current->index;
            }
            current = current->next;
        }
        current = push_swap->b;
        int count = 0;
        while (current && current->index != max_index) {
            count++;
            current = current->next;
        }
        if (count <= stack_size(push_swap->b) / 2) {
            while (push_swap->b->index != max_index) {
                rb(push_swap);
            }
        } else {
            while (push_swap->b->index != max_index) {
                rrb(push_swap);
            }
        }
        pa(push_swap);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [numbers...]\n", argv[0]);
        return 1;
    }

    t_push_swap push_swap;
    push_swap.a = NULL;
    push_swap.b = NULL;

    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&push_swap.a, value);
    }

    printf("Pila original: ");
    print_stack(push_swap.a);

    index_stack(push_swap.a);

    k_sort1(&push_swap);
    k_sort2(&push_swap);

    printf("Pila ordenada: ");
    print_stack(push_swap.a);

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

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
    int index = 0;
    t_stack *current = *stack;
    while (current != NULL) {
        current->index = index++;
        current = current->next;
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
            if (push_swap->a != NULL) { // Verificar si push_swap->a no es nulo
                rotate(&(push_swap->a));
                printf("ra\n");
            }
        }
    }
}


void k_sort2(t_push_swap *push_swap) {
    int length = stack_size(push_swap->b);
    int *index_array = malloc(length * sizeof(int));

    // Almacenar los índices de los elementos en un array auxiliar
    t_stack *current = push_swap->b;
    for (int i = 0; i < length; i++) {
        index_array[i] = current->index;
        current = current->next;
    }

    // Variable para seguir la cantidad de movimientos realizados
    int moves = 0;

    // Corregimos la condición del bucle principal
    while (length > 0 && push_swap->b != NULL) {
        int rb_count = count_r(push_swap->b, length - 1);
        int rrb_count = length - rb_count;

        // Optimizar las rotaciones
        if (rb_count <= rrb_count) {
            while (push_swap->b != NULL && index_array[0] != length - 1) {
                rotate(&(push_swap->b));
                printf("rb\n");
                moves++;
                if (moves > length) {
                    // Si los movimientos exceden la longitud de la pila, salimos del bucle
                    free(index_array);
                    return;
                }
            }
        } else {
            while (push_swap->b != NULL && index_array[0] != length - 1) {
                reverse_rotate(&(push_swap->b));
                printf("rrb\n");
                moves++;
                if (moves > length) {
                    // Si los movimientos exceden la longitud de la pila, salimos del bucle
                    free(index_array);
                    return;
                }
            }
        }
        
        // Simplificar la lógica de decisión
        if (push_swap->b != NULL && index_array[0] != length - 1) {
            pa(push_swap);
            printf("pa\n");
        }

        // Actualizar el array de índices
        for (int i = 0; i < length - 1; i++) {
            index_array[i] = index_array[i + 1];
        }
        
        length--;
    }

    free(index_array);
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
        printf("%d(%d) ", stack->content, stack->index);
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

    printf("Original stack: ");
    print_stack(push_swap.a);

    assign_indices(&(push_swap.a));

    printf("Stack with indices: ");
    print_stack(push_swap.a);

    k_sort1(&push_swap);
    printf("After k_sort1: ");
    print_stack(push_swap.a);

    k_sort2(&push_swap);
    printf("After k_sort2: ");
    print_stack(push_swap.a);

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

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

    printf("Original stack: ");
    print_stack(push_swap.a);

    assign_indices(&(push_swap.a));

    printf("Stack with indices: ");
    t_stack *tmp = push_swap.a;
    while (tmp) {
        printf("%d(%d) ", tmp->content, tmp->index);
        tmp = tmp->next;
    }
    printf("\n");

    k_sort1(&push_swap);
    k_sort2(&push_swap);

    printf("Sorted stack: ");
    print_stack(push_swap.a);

    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

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

    k_sort1(&push_swap);
    k_sort2(&push_swap);

    printf("Sorted stack: ");
    print_stack(push_swap.a);

    return 0;
} 
















   




