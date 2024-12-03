/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:44:28 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/21 21:44:28 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepeat(char *str, int n)
{
	char	*res;
	int		i;
	int		res_i;
	int		j;

	i = 0;
	j = 0;
	res_i = 0;
	if (n <= 0)
		return (NULL);
	res = (char *)malloc((ft_strlen(str) * n) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (i < n)
	{
		while (str[j])
			res[res_i++] = str[j++];
		j = 0;
		i++;
	}
	res[res_i] = '\0';
	return (res);
}
