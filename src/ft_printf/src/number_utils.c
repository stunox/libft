/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:39:53 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/20 13:31:48 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == (2L << 62))
		return (20);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	nbrlen_hex(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_u_itoa(unsigned int n)
{
	char			*res;
	int				i;
	unsigned int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	i = nbrlen(n);
	nb = n;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (nb > 0)
	{
		res[--i] = ((int)(nb % 10)) + '0';
		nb /= 10;
	}
	return (res);
}

void	put_u_nbr(unsigned int n)
{
	if (n >= 10)
	{
		put_u_nbr(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
}
