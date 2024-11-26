/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:50:47 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/24 17:50:56 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memlen(void *ptr)
{
	size_t	len;

	len = 0;
	while (*(char *)ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}
