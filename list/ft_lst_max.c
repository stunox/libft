/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:26:34 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/21 19:26:34 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_max(t_list *lst)
{
	t_list	*max;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	max = lst;
	tmp = lst;
	while (tmp)
	{
		if (ft_memcmp(tmp->content, max->content, sizeof(int)) > 0)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
