/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:52:48 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/22 16:54:08 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	FUNCTIONS PRE:
		tf_	=	test flag.
		ch_	=	check. Return a boolean.
		ft_ =	function.
*/

#include "./include/ft_printf.h"

int		ch_size (int d1, int d2)
{
	int	r;

	r = 0;
	printf ("SIZE:\n\t");
	if (d1 == d2)
		r = 1, printf ("SUCCESS");
	else
		printf ("FAILURE");
	printf ("\n");
	return (r);
}

/*
	• %c print a single character.
	• %s print a string of characters.
	• %p The void * pointer argument is printed in hexadecimal.
	• %d print a decimal (base 10) number.
	• %i print an integer in base 10.
	• %u print an unsigned decimal (base 10) number.
	• %x print a number in hexadecimal (base 16). También X.
	• %% print a percent sign.
*/

int	main(void)
{
	char	*d = "4242";
	int		d1 = 0;
	int		d2 = 0;

	d1 = printf(" %c %c %c \n", 0, '1', '2');
	d2 = ft_printf(" %c %c %c \n", 0, '1', '2');
	printf("Retornos: [%d][%d]\n", d1, d2);
	return (0);
}
