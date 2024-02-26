/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:17 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/23 18:47:43 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_pf(int n, int *i)
{
	long int	copia;

	copia = n;
	if (copia < 0)
	{
		copia = (copia * -1);
		write(1, "-", 1);
		
	}
	if (copia > 9)
	{
		ft_putnbr_pf(copia / 10, i);
		ft_putchar_pf((copia % 10) + '0', i);
	}
	else
	{
		ft_putchar_pf(copia + '0', i);
	}
}

