/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:40:13 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/20 13:31:06 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*repeat_char(char c, int n)
{
	char	*res;
	int		i;

	if (n <= 0)
		return (NULL);
	res = (char *)malloc(n + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = c;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_stradd(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
