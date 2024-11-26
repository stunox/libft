/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:53:28 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/22 09:53:28 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *lst, int index)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
