/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntero_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:57 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/27 19:57:35 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_print_prefix(int *i)
{
	ft_putstr_pf("0x", i);
}

void	ft_print_hex_digit(unsigned long n, int *i)
{
	const char	*base;

	base = "0123456789abcdef";
	ft_putchar_pf(base[n], i);
}

void	ft_calculate_hex_length(unsigned long n, int *len)
{
	unsigned long	temp;

	temp = n;
	*len = 0;
	while (temp != 0)
	{
		temp /= 16;
		(*len)++;
	}
}

void	ft_puntero_pf(void *ptr, int *i)
{
	unsigned long	n;
	int				len;

	n = (unsigned long)ptr;
	ft_print_prefix(i);
	if (n == 0)
	{
		ft_putchar_pf('0', i);
		return ;
	}
	ft_calculate_hex_length(n, &len);
	while (len > 0)
	{
		len--;
		ft_print_hex_digit((n >> (4 * len)) & 0xf, i);
	}
}
