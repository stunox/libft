/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:25 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:25 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **lst)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	prev = NULL;
	current = *lst;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	*lst = prev;
}
