/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:01:29 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 13:01:29 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_delone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
	{
		(*del)(lst->content);
	}
	free(lst);
}
