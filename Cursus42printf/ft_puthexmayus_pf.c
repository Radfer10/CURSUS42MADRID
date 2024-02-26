/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmayus_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:42:21 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/26 14:43:29 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthexmayus_pf(unsigned int n, int *i)
{
	char	hex[] = "0123456789ABCDEF";

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
