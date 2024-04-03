/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:24:54 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/02 18:07:03 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * 1);
		if (new_s == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
			new_s[j++] = s1[i++];
		j = 0;
		while (s2[j])
			new_s[i++] = s2[j++];
		new_s[i] = '\0';
		return (new_s);
	}
	return (NULL);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*initialize_buffer(char *buffer)
{
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	return (buffer);
}
