/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:20:53 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 21:45:49 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (i < size && dst[i] != '\0')
		i++;
	if (i == size)
		return (size + src_len);
	j = 0;
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
	{
		dst[i + j] = '\0';
	}
	else if (size > 0)
		dst[size - 1] = '\0';
	return (dst_len + src_len);
}
/*int main()
{
	char	*dst[50];
	char	*src[] = "Hola que tal";
	size_t	size = '12';
	size_t	result = ft_strlcat(dst, src, sizeof(dst));
	printf("%c\n", dst);
	printf("%zu\n", result);
	return (0);
}*/
