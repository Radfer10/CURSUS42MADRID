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

// Función para contar el número de elementos en una pila
int stack_size(t_stack *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

// Función para encontrar el número máximo en la pila
int find_max(t_stack *stack) {
    int max = INT_MIN;
    while (stack != NULL) {
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
    }
    return max;
}

// Función para contar el número de bits en un número
int num_bits(int num) {
    int bits = 0;
    while (num > 0) {
        bits++;
        num >>= 1;
    }
    return bits;
}

// Función para manipular las pilas
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

void ra(t_push_swap *push_swap) {
    t_stack *tmp;
    t_stack *first;

    if (push_swap->a && push_swap->a->next) {
        first = push_swap->a;
        push_swap->a = push_swap->a->next;
        first->next = NULL;
        tmp = push_swap->a;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = first;
    }
}

void rra(t_push_swap *push_swap) {
    t_stack *tmp;
    t_stack *second_last;

    if (push_swap->a && push_swap->a->next) {
        tmp = push_swap->a;
        while (tmp->next->next)
            tmp = tmp->next;
        second_last = tmp;
        tmp = tmp->next;
        second_last->next = NULL;
        tmp->next = push_swap->a;
        push_swap->a = tmp;
    }
}

// Función de burbuja para asignar índices a los elementos del stack
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

    // Encuentra el índice máximo en la pila
    while (node) {
        if (node->index > max)
            max = node->index;
        node = node->next;
    }

    // Calcula el número de bits necesarios para representar el índice máximo
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
            if (((head_a->index >> bit_position) & 1) == 1)
            {
                ra(push_swap);
                printf("ra\n");
            }
            else
            {
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

    // Ordenar la pila usando Radix Sort
    sorter(&push_swap);

    printf("Pila ordenada: ");
    print_stack(push_swap.a);

    return 0;
}