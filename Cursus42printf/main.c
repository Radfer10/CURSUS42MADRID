/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:57:19 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/27 18:07:20 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int main() {
	int	nb = 1;
    int num = 123;
	const char c = 'A';
    char *str = "Hola, mundo!";
    unsigned int unum = 456;
    void *ptr = &num;

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
}
