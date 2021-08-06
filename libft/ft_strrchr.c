/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:07:51 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/04 11:21:52 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*dst;

	dst = s;
	while (*dst)
		dst++;
	if (c == '\0')
		return ((char *)dst);
	while (dst-- != s)
	{
		if (*dst == (char)c)
			return ((char *)dst);
	}
	return (NULL);
}
