/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:16:27 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:00 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
    int             content;
    unsigned int    index;
    struct  s_stack *next;
}   t_stack;

typedef struct s_push_swap
{
    t_stack *a;
    t_stack *b;
}   t_push_swap;
#endif