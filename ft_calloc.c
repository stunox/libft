/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:30:42 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/06 16:45:44 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	char	*ptr;
	size_t	total;
	size_t	i;

	total = count * size;
	res = malloc(total);
	if (!res)
		return (NULL);
	ptr = (char *)res;
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return (res);
}

void	*init_mem(int len, int size, char type)
{
	void	*ptr;

	if (type == 'm')
	{
		ptr = malloc(len * size);
		return (ptr);
	}
	else if (type == 'c')
	{
		ptr = ft_calloc(len, size);
		return (ptr);
	}
	return (NULL);
}
