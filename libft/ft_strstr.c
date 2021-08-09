/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:19:46 by amateo-r          #+#    #+#             */
/*   Updated: 2021/05/24 12:04:11 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (*needle == 0)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (needle[j] == haystack[k])
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
				k++;
			}
		}
	}
	return (NULL);
}
