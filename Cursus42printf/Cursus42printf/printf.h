/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:06:19 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/23 19:11:02 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

void	ft_putchar_pf(char c, size_t *cont);
void	ft_putnbr_pf(int n, size_t *cont);
void	ft_putstr_pf(char *str, size_t *cont);
void    ft_putunbr_pf(unsigned int n, size_t *cont);
#endif
