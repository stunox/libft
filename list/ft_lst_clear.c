/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:01:24 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 13:01:24 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;
	t_list	*next;

	actual = *lst;
	while (actual)
	{
		next = actual->next;
		ft_lst_delone(actual, del);
		actual = next;
	}
	*lst = NULL;
}
