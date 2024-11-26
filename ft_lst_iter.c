/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:00:37 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 13:00:37 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_iter(t_list *lst, void (*f)(void *))
{
	t_list	*actual;

	if (!lst || !f)
		return ;
	actual = lst;
	while (actual)
	{
		(*f)(actual->content);
		actual = actual->next;
	}
}
