/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:35:31 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/06 16:38:23 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[i]);
	if (s[0] == '\0' && c != '\0')
		return (NULL);
	while (--i > 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}
