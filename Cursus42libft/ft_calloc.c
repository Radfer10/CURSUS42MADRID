/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:44:43 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 22:43:02 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
/*int main() {
    int	num_elements =  5;
    size_t size_of_element = sizeof(int);
    int *array = ((int *)ft_calloc(num_elements, size_of_element));
	int i = 0;
    while (i < num_elements) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    free(array);
    return  0;
}*/
