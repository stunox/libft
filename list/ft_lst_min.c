/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:27:34 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/21 19:27:34 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_min(t_list *lst)
{
	t_list	*min;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	min = lst;
	tmp = lst;
	while (tmp)
	{
		if (ft_memcmp(tmp->content, min->content, sizeof(int)) < 0)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
