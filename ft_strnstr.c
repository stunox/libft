/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:05:33 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 17:22:20 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0 && haystack[0] != '\0')
		return (NULL);
	i = 0;
	needle_len = ft_strlen(needle);
	while (haystack[i] && i < (len - needle_len + 1))
	{
		if (haystack[i] == needle[0] && ft_strncmp(&(haystack[i]), needle,
				needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
