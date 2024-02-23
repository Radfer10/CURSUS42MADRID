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

void	ft_putnbr_pf(int n, size_t *cont)
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
		ft_putnbr_pf(copia / 10, cont);
		ft_putchar_pf((copia % 10) + '0', cont);
	}
	else
	{
		ft_putchar_pf(copia + '0', cont);
	}
}

