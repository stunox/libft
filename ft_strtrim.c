/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:34:24 by nbasheer          #+#    #+#             */
/*   Updated: 2024/10/12 15:34:24 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	strlen_excluding(const char *s1, const char *set, size_t len)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (s1[i] && ft_strchr(set, s1[i]))
// 		i++;
// 	j = i;
// 	i = len - 1;
// 	while (i > j && ft_strchr(set, s1[i]))
// 		i--;
// 	return (i - j + 1);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	start;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0 || !set || set[0] == '\0')
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = len - 1;
	while (i > start && ft_strchr(set, s1[i]))
		i--;
	res = ft_substr(s1, start, i - start + 1);
	return (res);
}
