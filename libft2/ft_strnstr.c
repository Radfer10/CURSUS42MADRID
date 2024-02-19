/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:51:35 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 20:52:58 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	const char	*haystack = "Hello, world";
	const char	*needle = "world";
	const char	*result;

	result = ft_strnstr(haystack, needle, 13);
	if (result != NULL)
	{
		printf("La subcadena %s fue encontrada en la posicion %ld", needle,
			result - haystack);
	} else {
		printf("La subcadena %s no fue encontrada", needle);
	}
	return (0);
}*/
