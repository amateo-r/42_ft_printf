/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:01:15 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/28 19:46:11 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// This function set prederminated values for a printf return.
t_printdata	*t_data_initializer(va_list args, t_printdata *pd)
{
	va_copy(pd->args, args);
	pd->width = 0;
	pd->pre = 0;
	pd->ret = 0;
	pd->pad = 0;
	pd->zero = 0;
	pd->minus = 0;
	pd->space = 0;
	pd->sign = 0;
	pd->apost = 0;
	pd->point = 0;
	return (pd);
}

// Print stuff on screen unga unga, but WHY is print(F) and not print
int	ft_printf(const char *fmt, ...)
{
	t_printdata	*pd;
	va_list		ap;
	int			i;

	i = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	pd = (t_printdata *)malloc (sizeof(t_printdata));
	t_data_initializer(ap, pd); // Después de este, va_start(pd->args, format); Habría que eliminar va_copy, y el 1º va_start, va_end.
	va_end(ap);
	i = -1;
	while (fmt[++i] != '\0')
	{
		if (fmt[i] == '%')
			 i = ft_eval_flag(fmt, i + 1, pd);
		else
			pd->ret += write(1, &fmt[i], 1);
	}
	va_end(pd->args);
	free(pd);
	return (pd->ret);
}
