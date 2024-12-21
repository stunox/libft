/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:07:24 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 17:41:33 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*str;
	size_t			i;

	if (num <= 0)
		return (ptr);
	str = (unsigned char *)ptr;
	i = 0;
	while (i < num)
		str[i++] = (unsigned char)value;
	return (ptr);
}
