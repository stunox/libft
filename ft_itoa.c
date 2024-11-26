/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:39:42 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 18:13:51 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nblen(int n)
{
	int	len;
	int	nb;

	len = 1;
	if (n == 0)
		return (1);
	nb = n;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	char	*s;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = (char [2]){0, 0};
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	i = nblen(n);
	res = (char *)malloc((i) * sizeof(char));
	if (!res)
		return (NULL);
	res[--i] = 0;
	while (i >= 0)
	{
		res[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_strjoin(s, res));
}
