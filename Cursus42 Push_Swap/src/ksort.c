/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:04:31 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/24 21:27:15 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_array(t_stack **array, t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i++] = stack;
		stack = stack->next;
	}
}

void	sort_array(t_stack **array, int size)
{
	int		i;
	int		j;
	t_stack	*tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i]->content > array[j]->content)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indices(t_stack **stack)
{
	t_stack	**array;
	int		size;
	int		i;

	size = stack_size(*stack);
	if (size <= 1)
		return ;
	array = malloc(size * sizeof(t_stack *));
	if (!array)
	{
		ft_printf("Memory allocation error\n");
		exit(1);
	}
	fill_array(array, *stack, size);
	sort_array(array, size);
	i = 0;
	while (i < size)
	{
		array[i]->index = i;
		i++;
	}
	free(array);
}

void	k_sort1(t_push_swap *push_swap)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(push_swap->a_size) * 13.634 / 10;
	while (push_swap->a != NULL)
	{
		if (push_swap->a->index <= i)
		{
			pb(push_swap);
			i++;
		}
		else if (push_swap->a->index <= i + range)
		{
			pb(push_swap);
			if (push_swap->b && push_swap->b->next)
				rb(push_swap);
			++i;
		}
		else
			ra(push_swap);
	}
}

void	k_sort2(t_push_swap *push_swap)
{
	int	length;
	int	rb_count;
	int	rrb_count;

	length = stack_size(push_swap->b);
	while (length > 0 && push_swap->b != NULL)
	{
		rb_count = count_r(push_swap->b, length - 1);
		rrb_count = stack_size(push_swap->b) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (push_swap->b->index != length - 1)
				rb(push_swap);
		}
		else
		{
			while (push_swap->b->index != length - 1)
			{
				reverse_rotate(&(push_swap->b));
				ft_printf("rrb\n");
			}
		}
		pa(push_swap);
		length--;
	}
}
