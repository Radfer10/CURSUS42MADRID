/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:30:01 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 22:06:35 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	map_function(unsigned int index, char c)
{
	if (index % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!s || !str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*int main()
{
	const char	*i = "Hola que tal";
	char		*result = ft_strmapi((char *)i, map_function);
	printf("%s\n", i);
	printf("%s\n", result);
	return (0);
}*/
