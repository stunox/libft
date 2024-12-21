/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:00:57 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 13:00:57 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new_list;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	first = ft_lst_new((*f)(lst->content));
	if (!first)
		return (NULL);
	new_list = first;
	lst = lst->next;
	while (lst)
	{
		next = ft_lst_new((*f)(lst->content));
		if (!next)
		{
			ft_lst_clear(&new_list, del);
			return (NULL);
		}
		ft_lst_addback(&new_list, next);
		lst = lst->next;
	}
	return (first);
}
