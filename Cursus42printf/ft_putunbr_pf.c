/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:08:19 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:57 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_pf(unsigned int n, int *i)
{
	if (n < 0)
	{
		ft_putstr_pf("Error\n", i);
	}
	else if (n > 9)
	{
		ft_putnbr_pf(n / 10, i);
		ft_putchar_pf((n % 10) + '0', i);
	}
	else
	{
		ft_putchar_pf(n + '0', i);
	}
}
