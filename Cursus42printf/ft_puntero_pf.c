/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntero_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:54:57 by rde-migu          #+#    #+#             */
/*   Updated: 2024/03/08 18:04:21 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	*len = 0;
	while (n != 0)
	{
		n /= 16;
		(*len)++;
	}
}

void	print_hex_recursive(unsigned long n, int len, int *i)
{
	if (len == 0)
		return ;
	print_hex_recursive(n / 16, len - 1, i);
	ft_print_hex_digit(n % 16, i);
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
	print_hex_recursive(n, len, i);
}
