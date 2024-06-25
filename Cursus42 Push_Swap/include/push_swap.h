/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:20:40 by rde-migu          #+#    #+#             */
/*   Updated: 2024/06/24 18:59:59 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	int				a_size;
	int				b_size;
}					t_push_swap;

/*push_swap*/
void				push_swap_main(t_push_swap *push_swap);
int					is_sorted(t_stack *stack);
/*parseo*/
long long			ft_atoll(const char *str);
int					ft_atoi(const char *str);
void				display_error(char *message, int exit_code);
char				**ft_split(const char *str, char delimiter);
void				free_2d(char **array);
int					check_digits(int argc, char **argv);
int					contains_duplicate(t_stack *stack, int value);
int					contains_non_numeric_characters(const char *str);
int					contains_invalid_signs(const char *str);
void				check_range(char **s_numbers, t_stack **stack);
void				add_to_stack(t_stack **stack, int num);
void				parse_arguments(t_push_swap *ps, int argc, char **argv);
void				add_numbers_to_stack(t_push_swap *ps, char **s_numbers);
void				arg_parse(t_push_swap *ps, int argc, char **argv);

/*accions*/
t_stack				*swap(t_stack *stack);
void				sa(t_push_swap *push_swap);
void				sb(t_push_swap *push_swap);
void				ss(t_push_swap *push_swap);
void				push(t_stack **stack_a, t_stack **stack_b);
void				pa(t_push_swap *push_swap);
void				pb(t_push_swap *push_swap);
void				rotate(t_stack **stack);
void				ra(t_push_swap *push_swap);
void				rb(t_push_swap *push_swap);
void				rr(t_push_swap *push_swap);
void				reverse_rotate(t_stack **stack);
void				rra(t_push_swap *push_swap);
void				rrb(t_push_swap *push_swap);
void				rrr(t_push_swap *push_swap);
/*sorting*/
int					stack_size(t_stack *stack);
int					count_r(t_stack *stack, int index);
int					ft_sqrt(int num);
void				assign_indices(t_stack **stack);
void				fill_array(t_stack **array, t_stack *stack, int size);
void				sort_array(t_stack **array, int size);
int					get_min_index(t_stack *stack);
void				k_sort1(t_push_swap *push_swap);
void				k_sort2(t_push_swap *push_swap);
void				k_sort(t_push_swap *push_swap);
void				sort_2(t_push_swap *push_swap);
void				compare_and_swap_3(t_push_swap *push_swap, t_stack *first,
						t_stack *second, t_stack *third);
void				sort_3(t_push_swap *push_swap);
void				sort_4(t_push_swap *push_swap);
void				sort_stack_5(t_push_swap *push_swap);
void				special_cases_5(t_push_swap *push_swap, int position);
void				sort_5(t_push_swap *push_swap);
int					where_small(t_stack *stack, t_stack *min_node);
/*main*/
int					main(int argc, char *argv[]);
void				print_stack(t_stack *stack);
void				free_stack(t_stack **stack);
/*sorting_utils*/
t_stack				*find_min(t_stack *stack);
#endif