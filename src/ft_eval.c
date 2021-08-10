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

#include "../include/ft_printf.h"

/* Evaluate the characteristics of the allowed formats (cspdiuxX%). */
t_printdata	*ft_eval_format(const char *fmt, int index, t_printdata *pd)
{
	if (fmt[index] == 'c')
		ft_write_c(pd);
	else if (fmt[index] == 's')
		ft_write_s(pd);
	else if (fmt[index] == 'p')
		ft_write_p(pd);
	else if (fmt[index] == 'd' || fmt[index] == 'i')
		ft_write_d(pd);
	else if (fmt[index] == 'u')
		return (pd);
	else if (fmt[index] == 'x' || fmt[index] == 'X')
		ft_write_x(pd, fmt[index] - 23);
	else if (fmt[index] == '%')
		ft_write_per(pd);
	return (pd);
}

/*	Para que cada vez que se registren los datos de un formato,
	no haya solapamiento con el anterior. */
t_printdata	*ft_reset_pd(t_printdata *pd)
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

void	ft_print_tpd (t_printdata *pd)
{
	printf("[pre{%d}, pad{%d}, zero{%d}, minus{%d}, space{%d}, sign{%d}, apost{%d}, point{%d}]", pd->pre, pd->pad, pd->zero, \
	pd->minus, pd->space, pd->sign, pd->apost, pd->point);
	return ;
}

/*	Evaluate the type of formats when '%' is detected. */
/* 	SIN EJECUTAR EL BUCLE FUNCIONA CASI TODO. */
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
	ft_eval_format(fmt, index, pd);
	return (index);
}
