/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:17:04 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/26 19:31:18 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


void	ft_format(va_list args,const char *str, int *i)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), i);
	if (*str == 'i')
		ft_putnbr_pf(va_arg(args, int), i);
	if (*str == 'd')
		ft_putnbr_pf(va_arg(args, int), i);
	if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), i);
	if (*str == 'u')
		ft_putunbr_pf(va_arg(args, unsigned int), i);
	if (*str == 'x')
		ft_puthex_pf(va_arg(args, unsigned int), i);
	if (*str == 'X')
		ft_puthexmayus_pf(va_arg(args, unsigned int), i);
	if (*str == 'p')
		ft_puntero_pf(va_arg(args, void *), i);
	else if (*str == '%')
		ft_putchar_pf(*str, i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;

	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(args, str + i, &len);
		}
		else 
			ft_putchar_pf(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
/*int main() {
	int	nb = 1;
    int num = 123;
	const char c = 'A';
    char *str = "Hola, mundo!";
    unsigned int unum = 456;
    void *ptr = 123;

	ft_printf("Esto es un char: %c\n", c);
    ft_printf("Esto es un numero: %i\n", nb);
    ft_printf("Este es un número entero: %d\n", num);
    ft_printf("Este es el mismo número en formato hexadecimal: %x\n", num);
	ft_printf("Este es el mismo número en formato hexadecimal en mayúsculas: %X\n", num);
    ft_printf("Esta es una cadena de caracteres: %s\n", str);
    ft_printf("Este es un número sin signo: %u\n", unum);
	ft_printf("Esto es n símbolo de porcentaje: %%\n");
    ft_printf("Este es el puntero en formato hexadecimal: %p\n", ptr);


    return 0;
}*/


