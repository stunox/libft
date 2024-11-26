/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:49:59 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 17:39:35 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	*i;
	size_t	start;
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	i = (size_t [2]){0, 0};
	words = count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i[0]] && i[1] < words)
	{
		while (s[i[0]] && s[i[0]] == c)
			i[0]++;
		start = i[0];
		while (s[i[0]] && s[i[0]] != c)
			i[0]++;
		res[i[1]++] = ft_substr(s, start, i[0] - start);
		while (s[i[0]] && s[i[0]] == c)
			i[0]++;
	}
	res[i[1]] = NULL;
	return (res);
}
