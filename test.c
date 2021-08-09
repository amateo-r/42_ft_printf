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

#include "./include/libftprintf.h"

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

// Test que compara la flag '0' para todos sus casos.
void	tf_zero ()
{
	char			*s1 = "1234567891";
	char			*s2 = "";
	char			c = 'a';
	int				d1 = 0;
	int				d2 = 0;
	int				ud = -42;
	
	printf ("\n\n\t---- TEST ZERO FLAG ----\n");
	printf ("\nSIMPLE ZERO - NO PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: %0s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %0s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - SAME PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: %011s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %011s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - LOW PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: %010s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %010s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - HIGH PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: %020s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %020s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nNUMERIC CONVERSIONS\n");
	printf ("\nNO ZERO - NO PRECISION NUMERIC CONVERSION\n");
	d1 = printf("rfo: %d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - PRECISION ZERO NUMERIC CONVERSION\n");
	d1 = printf("rfo: %0d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %0d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - SAME PRECISION NUMERIC CONVERSION\n");
	d1 = printf("rfo: %02d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %02d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - LOW PRECISION NUMERIC CONVERSION\n");
	d1 = printf("rfo: %01d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %01d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - HIHG PRECISION NUMERIC CONVERSION\n");
	d1 = printf("rfo: %010d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %010d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE ZERO - HIGH PRECISION NUMERIC CONVERSION RIGHT\n");
	d1 = printf("rfo: %0-10d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %0-10d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);

	printf ("\nSIMPLE ZERO - HIGH PRECISION NUMERIC CONVERSION MULTIPLE MINUS LEFT\n");
	d1 = printf("rfo: %0----10d, [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %0----10d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);
	return ;

	printf ("\nSIMPLE ZERO - HIGH PRECISION NUMERIC CONVERSION MULTIPLE MINUS RIGHT\n");
	d1 = printf("rfo: %010----d [%s]\n", ud, s2);
	d2 = ft_printf ("rfc: %010----d, [%s]\n", ud, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);
	return ;
}

// Test que compara la flag ' ' para toddos sus casos.
void	tf_space ()
{
	char			*s1 = "1234567891";
	char			*s2 = "";
	char			c = 'a';
	int				d1 = 0;
	int				d2 = 0;
	int				ud = -42;
	
	printf ("\n\n\t---- TEST SPACE FLAG ----\n");
	printf ("\nSPACE - NO PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: % s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - SAME PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: % 10s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 10s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - LOW PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: % 7s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 7s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - HIGH PRECISION NON NUMERIC CONVERSION\n");
	d1 = printf("rfo: % 20s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 20s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - LOW PRECISION NON NUMERIC CONVERSION LEFT\n");
	d1 = printf("rfo: % -7s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % -7s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - SAME PRECISION NON NUMERIC CONVERSION RIGHT\n");
	d1 = printf("rfo: % 10-s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 10-s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - LOW PRECISION NON NUMERIC CONVERSION RIGHT\n");
	d1 = printf("rfo: % 7-s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 7-s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - LOW PRECISION NON NUMERIC CONVERSION MULTIPLE MINUS RIGHT\n");
	d1 = printf("rfo: % 7-----s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 7-----s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - HIGH PRECISION NON NUMERIC CONVERSION RIGHT\n");
	d1 = printf("rfo: % 20-s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 20-s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSPACE - HIGH PRECISION NON NUMERIC CONVERSION MULTIPLE MINUS RIGHT\n");
	d1 = printf("rfo: % 20----s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: % 20----s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);
	return ;
}

// Test que compara la flag '.' para todos sus casos.
void	tf_point ()
{
	char			*s1 = "1234567891";
	char			*s2 = "";
	char			c = 'a';
	int				d1 = 0;
	int				d2 = 0;

	printf ("\n\n\t----- TEST POINT FLAG ----\n");
	printf ("\nSIMPLE POINT - NO PRECISION\n");
	d1 = printf("rfo: %.s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE POINT - HIGH PRECISION\n");
	d1 = printf("rfo: %.12s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.12s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE POINT - LOW PRECISION\n");
	d1 = printf("rfo: %.7s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.7s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE POINT - HIGH PRECISION MINUS LEFT\n");
	d1 = printf("rfo: %.-12s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.-12s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE POINT - HIGH PRECISION MULTIPLE MINUS LEFT\n");
	d1 = printf("rfo: %.----12s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.----12s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE POINT - HIGH PRECISION MINUS RIGHT\n");
	d1 = printf("rfo: %.7-s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.7-s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);

	printf ("\nSIMPLE POINT - HIGH PRECISION MULTIPLE MINUS RIGHT\n");
	d1 = printf("rfo: %.12----s, [%s]\n", s1, s2);
	d2 = ft_printf ("rfc: %.12----s, [%s]\n", s1, s2);
	printf ("rto: %d\n", d1);
	printf ("rtc: %d\n", d2);
	ch_size (d1, d2);
	return ;
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

void	tf_p_conversion()
{
	char			*s1 = "1234567891";
	char			*s2;
	char			*c = 'a';
	int				d1 = 42;
	int				*d2 = d1;

	printf ("\n\n\t----- TEST POINTER CONVERSION ----\n");
	printf ("\nSIMPLE POINT - NO PRECISION\n");
	d1 = printf("rfo: %p, [%p], [%p], [%p], [%p]\n", s1, s2, c, d1, d2);
	d2 = ft_printf ("rfc: %p, [%p], [%p], [%p], [%p]\n", s1, s2, c, d1, d2);
	printf ("rfo: %d\n", d1);
	return ;
}

void	tf_c_conversion()
{
	char	c1;
	char	c2;
	char	*s = "S";
	int		d1;
	int		d2;

	c1 = 'W';
	c2 = 'w';
	printf ("\n\n\t----- TEST CHAR CONVERSION ----\n");
	printf ("\nSIMPLE POINT - NO PRECISION\n");
	d1 = printf("rfo: %02-c, [%05c]\n", c1, c2);
	d2 = ft_printf ("rfc: %02-c, [%05c]\n", c1, c2);
	printf ("rfo: %d\n", d1);
	printf ("rfc: %d\n", d2);
	ch_size (d1, d2);
	return ;
}

// Per = percent -> '%'
void	tf_per_conversion ()
{
	int		d1;
	int		d2;

	printf ("\n\n\t----- TEST PERCENT CONVERSION ----\n");
	printf ("\nSIMPLE PERCENT - NO PRECISION\n");
	d1 = printf("rfo: %%, [%12-%]\n");
	d2 = ft_printf ("rfc: %%, [%12-%]\n");
	printf ("rfo: %d\n", d1);
	printf ("rfc: %d\n", d2);
	ch_size (d1, d2);
	return ;
}

int	main(void)
{
	// tf_point();
	// tf_zero();	//	DONETE MÁS O MENOS
	// tf_space();	//	DONETE MÁS O MENOS
	// tf_c_conversion();
	// tf_p_conversion();
	// tf_per_conversion();
	int d = 42;
	printf ("Hola %p\n", d);
	ft_printf ("Hola [2%p]\n", d);
	return (0);
}
