/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:49:04 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/24 17:55:38 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	len;
	void	*new;

	if (ptr == NULL)
		return (init_mem(1, size, 'm'));
	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	len = ft_memlen(ptr);
	if (len > size)
	{
		free(ptr + size);
		return (ptr);
	}
	else
	{
		new = init_mem(1, size, 'm');
		ft_memcpy(new, ptr, len);
		free(ptr);
		return (new);
	}
}
