/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_popfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:31 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:31 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_popfront(t_list **lst)
{
	void		*content;
	t_list		*tmp;

	if (!lst || !*lst)
		return (NULL);
	tmp = *lst;
	*lst = (*lst)->next;
	content = tmp->content;
	tmp->next = NULL;
	free(tmp);
	return (content);
}
