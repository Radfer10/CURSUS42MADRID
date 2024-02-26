/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntero_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:57 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/26 19:22:06 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_puntero_pf(void *ptr, int *i)
{
	unsigned long	n;
	const char		*base;

	n = (unsigned long)ptr;
	base = "0123456789abcdef";
	ft_putstr_pf( "0x", i);
	if (n == 0)
	{
		ft_putchar_pf('0', i);
		return;
	}
	else
	{
		while (n != 0)
		{
			ft_putchar_pf(base[n % 16], i);
			n /= 16;
		}
	}
}
