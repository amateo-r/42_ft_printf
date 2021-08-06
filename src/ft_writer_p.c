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

// Esencialmente un puntero es en formato %#x %llx %lx
// Exist esta opción: uintptr_t. Como es un tipo de dato, técnicmante, es legal, puesto que no es una función prohibida.
void	ft_write_p (t_printdata *pd)
{
	void	*p;

	p = va_arg(pd->args, void *);
	printf ("{[TEST write_p][%ld]}", p);
	return ;
}
