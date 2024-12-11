/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:21 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:21 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_search(t_list *lst, void *content)
{
	t_list	*tmp;

	tmp = lst;
	if (!content)
		return (NULL);
	while (tmp)
	{
		if (ft_memcmp(tmp->content, content, sizeof(content)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
