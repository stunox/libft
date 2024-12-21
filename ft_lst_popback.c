/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_popback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:38 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:38 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_popback(t_list **lst)
{
	void		*content;
	t_list		*tmp;

	if (!lst || !*lst)
		return (NULL);
	if (!(*lst)->next)
		return (ft_lst_popfront(lst));
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	content = tmp->content;
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		*lst = NULL;
	free(tmp);
	return (content);
}
