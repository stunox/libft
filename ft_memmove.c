/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:22:32 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 17:43:16 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			((char *)dest)[n] = ((const char *)src)[n];
	}
	return (dest);
}
