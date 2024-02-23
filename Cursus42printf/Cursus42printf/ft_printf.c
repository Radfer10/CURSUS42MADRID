/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:17:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/23 19:17:58 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format(va_list args, char *str, size_t *cont)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), cont);
	if (*str == 'i')
		ft_putnbr_pf(va_arg(args, int), cont);
	if (*str == 'd')
		ft_putnbr_pf(va_arg(args, int), cont);
	if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), cont);
	if (*str == 'u')
		ft_putunbr_pf(va_arg(args, unsigned int), cont);
	else if (*str == '%')
		ft_putchar_pf(*str, cont);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	cont;

	if(!str)
		return (0);
	cont = 0;
	va_start(args, str);
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &cont);
		}
		else 
			ft_putchar_pf(*str, &cont);
		str++;
	}
	va_end(args);
	return (cont);
}


