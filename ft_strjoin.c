/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:26:01 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 17:57:10 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	ls[2];

	ls[0] = ft_strlen(s1);
	ls[1] = ft_strlen(s2);
	res = (char *)malloc((ls[0] + ls[1]) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ls[0] + 1);
	ft_strlcat(res, s2, ls[0] + ls[1] + 1);
	return (res);
}
