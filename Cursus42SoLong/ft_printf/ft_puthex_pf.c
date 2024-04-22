/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:26:56 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/27 19:54:42 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_pf(unsigned int n, int *i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_pf(n / 16, i);
		ft_putchar_pf(hex[n % 16], i);
	}
	else
	{
		ft_putchar_pf(hex[n % 16], i);
	}
}
