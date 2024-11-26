/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:00:02 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/07 17:00:02 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int to_free)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	if (to_free)
		free(s);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", 0);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

void	ft_putnbr_hex(unsigned long long n, char type)
{
	char	*base;

	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_putnbr_hex(n / 16, type);
		ft_putchar_fd(base[n % 16], 1);
	}
	else
		ft_putchar_fd(base[n], 1);
}

int	print(const char *format, va_list args, int *ret)
{
	int	i;
	int	start;
	int	temp;

	start = 0;
	i = 0;
	while (format[i] != '\0')
	{
		start = i;
		while (format[i] && format[i] != '%')
		{
			i++;
			(*ret)++;
		}
		if (start < i)
			ft_putstr(ft_substr(format, start, i - start), 1);
		if (format[i] == '%' && format[i + 1])
		{
			temp = convert(format, i, args, ret);
			if (temp < 0)
				return (-1);
			i += temp;
		}
	}
	return (*ret);
}
