/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:24:37 by amateo-r          #+#    #+#             */
/*   Updated: 2021/08/05 13:24:40 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	ft_write_per (t_printdata *pd)
{
	char	*per;

	per = va_arg(pd->args, char *);
	if (pd->zero > 0)
		ft_ws_zero("%", pd);
	else if (pd->space)
		ft_ws_space("%", pd);
	else
	{
		ft_putstr_fd("%", 1);
		pd->ret++;
	}
	return ;
}
