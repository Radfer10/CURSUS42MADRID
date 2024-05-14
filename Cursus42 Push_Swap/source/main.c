/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:05:25 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/10 18:34:22 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push_swap *init_push_swap(void)
{
	t_push_swap *push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (push_swap == 0)
		return (0);
	push_swap->a = 0;
	push_swap->b = 0;
	return (push_swap);
}
int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}



bool is_sorted(t_stack *stack) {
    if (stack == NULL || stack->next == NULL) {
        // Si el stack está vacío o tiene solo un elemento, está ordenado
        return true;
    }

    // Recorremos el stack y comprobamos si cada elemento es menor o igual que el siguiente
    while (stack->next != NULL) {
        if (stack->content > stack->next->content) {
            // Si encontramos un elemento mayor que el siguiente, el stack no está ordenado
            return false;
        }
        stack = stack->next;
    }

    // Si llegamos al final del stack sin encontrar ningún problema, está ordenado
    return true;
}


t_stack *stack_last(t_stack *stack)
{
    if (stack == NULL)
        return NULL;
    while (stack->next != NULL)
        stack = stack->next;
    return (stack);
}


t_stack *add_back_new_stack(int content, t_stack *stack)
{
	t_stack *new;
	t_stack	*item;

	new = malloc(sizeof(t_stack));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = NULL;
	if (stack != NULL)
	{
		item = stack_last(stack);
		item->next = new;
	}
	else
		stack = new;
	return (stack);
}

t_stack *swap(t_stack *stack)
{
    t_stack *tmp;

    if (!stack || stack->next == NULL)
        return stack;
    tmp = stack->next;
    stack->next = tmp->next;
    tmp->next = stack;
    return tmp;
}


void	sa(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
}

void	sb(t_push_swap *push_swap)
{
	push_swap->b = swap(push_swap->b);
}

void	ss(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	push_swap->b = swap(push_swap->b);
}

void push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (*stack_b == 0)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void	pa(t_push_swap *push_swap)
{
	push(&push_swap->a, &push_swap->b);
}

void	pb(t_push_swap *push_swap)
{
	push(&push_swap->b, &push_swap->a);
}

t_stack *reverse_rotate(t_stack *stack)
{
    if (!stack || !stack->next)
        return stack; 
    t_stack *last = stack;
    t_stack *prev_to_last = 0;
    while (last->next)
    {
		
        prev_to_last = last;
		last = last->next;
        
    }
	prev_to_last->next = 0;
    last->next = stack;
	return last;
}

void	rra(t_push_swap *push_swap)
{
	push_swap->a = reverse_rotate(push_swap->a);
}

void	rrb(t_push_swap *push_swap)
{
	push_swap->b = reverse_rotate(push_swap->b);
}

void	rrr(t_push_swap *push_swap)
{
	push_swap->a = reverse_rotate(push_swap->a);
	push_swap->b = reverse_rotate(push_swap->b);
}

t_stack *rotate(t_stack *stack)
{
    if (!stack || !stack->next)
        return stack; 
    
    t_stack *first = stack;
    t_stack *second = stack->next;
    t_stack *last = stack;
    
	while (last->next)
    {
        last = last->next;
    }
	last->next = first;
    stack = second;
    first->next = NULL;
	return stack;
}


void	ra(t_push_swap *push_swap)
{
	push_swap->a = rotate(push_swap->a);
}

void	rb(t_push_swap *push_swap)
{
	push_swap->b = rotate(push_swap->b);
}

void	rr(t_push_swap *push_swap)
{
	push_swap->a = rotate(push_swap->a);
	push_swap->b = rotate(push_swap->b);
}


void print_push_swap(t_push_swap *push_swap)
{
	t_stack *tmp;

	tmp = push_swap->a;
	printf("Stack A:|");
	while (tmp != 0)
	{
		printf(" %d |", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = push_swap->b;
	printf("Stack B:|");
	while (tmp != 0)
	{
		printf(" %d |", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

t_stack *find_min(t_stack *stack)
{
	t_stack *min = stack;
	while (stack != NULL)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return min;
}

void sort_2(t_push_swap *push_swap)
{
    if (push_swap->a != NULL)
    {
        t_stack *node;

		if (is_sorted(push_swap->a))
			return;

        node = push_swap->a;
        if (node->next != NULL)
        {
            if (node->content > node->next->content)
                sa(push_swap);
        }
    }

}

void sort_3(t_push_swap *push_swap)
{
    if (push_swap->a != NULL)
    {
        t_stack *first_node;
        t_stack *second_node;
        t_stack *third_node;

		if (is_sorted(push_swap->a))
			return;

        first_node = push_swap->a;
        second_node = push_swap->a->next;
        third_node = push_swap->a->next->next;

        if (first_node->content > second_node->content && first_node->content > third_node->content)
            ra(push_swap);
        else if (second_node->content > first_node->content && second_node->content > third_node->content)
            rra(push_swap);
        
        if (push_swap->a->content > push_swap->a->next->content)
            sa(push_swap);
    }
}

void sort_4(t_push_swap *push_swap)
{
    if (push_swap->a != NULL)
    {
        t_stack *node;
        t_stack *min_node;
	if (!is_sorted(push_swap->a))
		return;

        min_node = find_min(push_swap->a); // Encontramos el nodo mínimo en la pila `a`

        if (min_node != NULL)
        {
            // Movemos el nodo mínimo al principio de la pila `a`
            while (push_swap->a != min_node)
            {
                if (push_swap->a->next == min_node)
                {
                    sa(push_swap); // Si el siguiente nodo es el mínimo, intercambiamos los dos nodos
                    break;
                }
                ra(push_swap); // Rotamos hacia arriba hasta que el nodo mínimo esté al principio
            }

            pb(push_swap); // Movemos el nodo mínimo a la pila `b`

            // Ordenamos la pila `a` sin utilizar sort3
            if (push_swap->a != NULL && push_swap->a->content > push_swap->a->next->content)
                sa(push_swap);

            // Ordenamos la pila `a` utilizando sort3
            sort_3(push_swap);

            pa(push_swap); // Movemos el nodo mínimo de la pila `b` a la pila `a`
        }
    }
}

void sort_5(t_push_swap *push_swap)
{
    if (push_swap == NULL || push_swap->a == NULL)
        return;

    t_stack *min_node = find_min(push_swap->a); // Encontramos el nodo mínimo en la pila `a`

	if (is_sorted(push_swap->a))
		return;

    if (min_node == NULL)
        return;

    // Movemos el nodo mínimo al principio de la pila `a`
    while (push_swap->a != min_node)
    {
        if (push_swap->a->next == min_node)
        {
            sa(push_swap); // Si el siguiente nodo es el mínimo, intercambiamos los dos nodos
            break;
        }
        ra(push_swap); // Rotamos hacia arriba hasta que el nodo mínimo esté al principio
    }

    pb(push_swap); // Movemos el nodo mínimo a la pila `b`

    // Ordenamos la pila `a` sin utilizar sort4
    if (push_swap->a != NULL && push_swap->a->content > push_swap->a->next->content)
        sa(push_swap);

    // Ordenamos la pila `a` utilizando sort4
    sort_4(push_swap);

    pa(push_swap); // Movemos el nodo mínimo de la pila `b` a la pila `a`
}






void	sort_stack(t_push_swap *push_swap)
{
	
	if (push_swap->a != NULL)
	{
		t_stack	*tmp;
		t_stack	*min_element;

		while (push_swap->a != NULL)
		{
			min_element = find_min(push_swap->a);
			tmp = push_swap->a;
			if (tmp == min_element)
			{
				pb(push_swap);
				printf("pb\n");
			}
			else 
			{
				ra(push_swap);
				printf("ra\n");
			}
		}
		while (push_swap->b != NULL)
		{
			pa(push_swap);
			printf("pa\n");
		}
	}
}



// Función para imprimir la pila
void printStack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("Content: %d, Index: %u\n", stack->content, stack->index);
        stack = stack->next;
    }
}


int main(int argc, char **argv)
{
	t_push_swap *push_swap;
	int cont;

	cont = 1;
	if (argc < 2)
	{
		printf("Error: Faltan argumentos\n");
		return (0);
	}
	push_swap = init_push_swap();
	if (push_swap == 0)
	{
		printf("Error al inicializar\n");
		return (0);
	}
	while (cont < argc)
	{
		push_swap->a = add_back_new_stack(ft_atoi(argv[cont]), push_swap->a);
		cont++;
	}
	// TODO index funcion
	/*printf("swap\n");
	push_swap->b = add_back_new_stack(5, push_swap->b);
	print_push_swap(push_swap);
	printf("sa\n");
	sa(push_swap);
	print_push_swap(push_swap);
	printf("push\n");
	print_push_swap(push_swap);
	printf("pa\n");
	pa(push_swap);
	print_push_swap(push_swap);
	printf("rotate\n");
	print_push_swap(push_swap);
	printf("ra\n");
	ra(push_swap);
	print_push_swap(push_swap);
	printf("reverse_rotate\n");
	print_push_swap(push_swap);
	printf("rra\n");
	rra(push_swap);
	print_push_swap(push_swap);*/
	printf("Stack inicial:\n");
	print_push_swap(push_swap);
	printf("Ordenando...\n");
	sort_5(push_swap);
	printf("Sttack ordenado:\n");
	print_push_swap(push_swap);
	return (0);
}