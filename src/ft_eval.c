/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:00:32 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/05 14:24:08 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

// Evaluate the characteristics of the allowed formats (cspdiuxX%)
t_printdata	*ft_eval_format(const char *fmt, int index, t_printdata *pd)
{
	if (fmt[index] == 'c')										//	NOT DONE: STARTED
		ft_write_c(pd);
	else if (fmt[index] == 's')									//	NOT DONE: semi-zero, point
		ft_write_s(pd);
	else if (fmt[index] == 'p')									//	NOT DONE
		ft_write_p(pd);
	else if (fmt[index] == 'd')									//	NOT DONE: STARTED
		ft_write_d(pd);
	else if (fmt[index] == 'i')									//	NOT DONE
		return (pd);
	else if (fmt[index] == 'u')									//	NOT DONE
		return (pd);
	else if (fmt[index] == 'x')									//	NOT DONE
		return (pd);
	else if (fmt[index] == 'X')									//	NOT DONE
		return (pd);
	else if (fmt[index] == '%')									//	NOT DONE: STARTED
		ft_write_per(pd);
	return (pd);
}

// Para que cada vez que se registren los datos de un formato, no haya solapamiento con el anterior.
t_printdata *ft_reset_pd (t_printdata *pd)
{
	pd->pre = 0;
	pd->pad = 0;
	pd->zero = 0;
	pd->minus = 0;
	pd->space = 0;
	pd->sign = 0;
	pd->apost = 0;
	pd->point = 0;
	return (pd);
}

//	Evaluate the type of formats when '%' is detected.
//	SIN EJECUTAR EL BUCLE FUNCIONA CASI TODO.
int	ft_eval_flag(const char *fmt, int index, t_printdata *pd)
{
	int	index_start;

	index_start = index;
	ft_reset_pd(pd);
	while (ch_format(fmt[index]) == 0)
	{
		if (fmt[index] == '#')
			pd->pad++;
		else if (fmt[index] == '0' && pd->zero == 0)
			fh_zero(pd, fmt, index_start + 1);
		else if (fmt[index] == '-')
			fh_minus(pd, fmt, index_start);
		else if (fmt[index] == ' ')
			fh_space(pd, fmt, index_start);
		else if (fmt[index] == '+')
			pd->sign++;
		else if (fmt[index] == '\'')
			pd->apost++;
		else if (fmt[index] == '.')
			fh_point(pd, fmt, index_start);
		index++;
	}
	// ft_putstr_fd("Char: ", 1);
	// ft_putchar_fd(fmt[index], 1);
	ft_eval_format(fmt, index, pd);
	return (index);
}
