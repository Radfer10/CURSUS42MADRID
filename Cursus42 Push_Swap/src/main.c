/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:11:09 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/18 05:33:14 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	display_error(char *message, int exit_code)
{
	ft_putendl_fd(message, 2);
	exit(exit_code);
}

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;
	t_stack		*tmp;

	if (argc < 2)
	{
		return (1);
	}
	push_swap.a = NULL;
	push_swap.b = NULL;
	push_swap.a_size = 0;
	arg_parse(&push_swap, argc, argv);
	assign_indices(&(push_swap.a));
	tmp = push_swap.a;
	while (tmp)
	{
		tmp = tmp->next;
	}
	push_swap_main(&push_swap);
	free_stack(&push_swap.a);
	free_stack(&push_swap.b);
	return (0);
}
