/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:17 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:17 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size_rev(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->prev;
		size++;
	}
	return (size);
}
