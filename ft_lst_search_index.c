/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_search_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:46 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/20 16:25:05 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_search_index(t_list *lst, void *content)
{
	t_list	*tmp;
	int		index;

	tmp = lst;
	index = 0;
	while (tmp)
	{
		if (ft_memcmp(tmp->content, content, sizeof(content)) == 0)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}
