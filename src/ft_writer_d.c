/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:23:58 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/03 13:24:00 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	ft_stupid_sign (int sign)
{
	if (sign)
		ft_putchar_fd('-', 1);
	return ;
}
void	ft_write_d (t_printdata *pd)
{
	char	*s;
	int		d;
	int		sign;

	d = va_arg(pd->args, int);
	sign = 0;
	if (!d)
		return ;
	if (d < 0)
		pd->pre -= 1, d *= -1, sign = 1;
	s = ft_itoa(d);
	if (pd->zero > 0)
		ft_stupid_sign(sign), ft_ws_zero (s, pd);
	else if (pd->space)
		ft_stupid_sign(sign), ft_ws_space(s, pd);
	else if (pd->point)
		ft_stupid_sign(sign), ft_ws_point(s, pd);
	else
	{
		ft_stupid_sign(sign);
		ft_putstr_fd(s, 1);
		pd->ret += ft_strlen(s);
	}
	if (sign)
		pd->ret++;
	return ;
}
