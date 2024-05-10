/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:05:25 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/10 18:27:53 by rde-migu         ###   ########.fr       */
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

int maxm(t_stack *stack)
{
    int max = stack->content;
    while (stack != NULL)
    {
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
    }
    return max;
}

// Función para realizar el ordenamiento por dígitos
void radixSort(t_stack **stack)
{
    int max = maxm(*stack);
    for (int place = 1; max / place > 0; place *= 10)
    {
        t_stack *output = NULL;
        t_stack *current = *stack;
        t_stack *prev = NULL;

        while (current != NULL)
        {
            int digit = (current->content / place) % 10;
            if (digit == 0)
                pa(current);
            else if (digit == 1)
                pb(current);
            // ... (similarly for other digits)

            prev = current;
            current = current->next;
            prev->next = output;
            output = prev;
        }

        *stack = output;
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
	sort_stack(push_swap);
	printf("Sttack ordenado:\n");
	print_push_swap(push_swap);
	return (0);
}