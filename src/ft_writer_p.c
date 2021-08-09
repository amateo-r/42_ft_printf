/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:50:34 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/05 15:50:36 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

/* Técnicamente esto es para cuando un p es nulo. */
void	ft_null_pointer (void)
{
	return ;
}

// Esencialmente un puntero es en formato %#x %llx %lx
// Exist esta opción: uintptr_t. Como es un tipo de dato, técnicmante
// , es legal, puesto que no es una función prohibida.
/* Pointer format output. */
void	ft_write_p(t_printdata *pd)
{
	void	*p;
	char	*str;
	int		len;
	int		i;

	p = va_arg(pd->args, void *);
	i = -1;
	if (!p)
		return ;
	len = ft_digits_base((unsigned long)p, 16);
	str = (char *)malloc(sizeof(char) * len);
	str = (char *)p;
	ft_putstr_fd("0x", 1);
	while (++i < len)
		ft_putchar_fd(str[i], 1);
	return ;
}
