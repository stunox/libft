/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:01:14 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 13:01:14 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_addfront(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}
