/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:36:23 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/03 13:36:25 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

/*
	A veces puede haber un número entre el formato y las flags.
	Esta función sirve para mover el puntero de ser así.
*/
int	ch_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == '%')
		return (1);
	else
		return (0);
}

// Checks a empty input value from a format.
int	ft_check(void *s)
{
	if (!s)
		return (0);
	return (1);
}

// [DEPRECATED]
int	ch_flag(t_printdata *pd)
{
	if (pd->minus > 0)
		return (1);
	else if (pd->zero > 0)
		return (1);
	else if (pd->space > 0)
		return (1);
	return (0);
}
