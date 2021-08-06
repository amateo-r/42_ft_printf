/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:35 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/08 12:09:37 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_newelemt;

	if (!f || !del || !lst)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		lst_newelemt = ft_lstnew(f(lst->content));
		if (!lst_newelemt)
			ft_lstclear(&lst_new, del);
		ft_lstadd_back(&lst_new, lst_newelemt);
		lst = lst->next;
	}
	return (lst_new);
}
