/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:53 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/07 16:59:53 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(const char *format, int i, va_list args, int *ret)
{
	t_flags				flag;
	t_arg				arg;

	init_flag(&flag, format, i + 1);
	if (ft_strchr("cspdiuxX%", flag.type) == NULL)
		return (-1);
	arg = get_arg(flag, args);
	print_conversion(flag, arg, ret);
	return (flag.len);
}

int	h_neg(int n)
{
	if (n < 0)
		return (2147483647);
	return (n);
}

int	get_len(t_flags flag, t_arg arg)
{
	int	len;

	if (ft_strchr("cp", flag.type) != NULL)
		len = max(max(arg.len, flag.prec), flag.width);
	else if (ft_strchr("di", flag.type) != NULL)
		len = max(flag.width, max(arg.len, flag.prec + (arg.nbr < 0))
				+ ((flag.plus || flag.space) && arg.nbr >= 0));
	else if (ft_strchr("uxX", flag.type) != NULL)
		len = max(flag.width, max(arg.len, flag.prec));
	else if (flag.type == 's')
	{
		if (arg.len == 0 && flag.prec > flag.width)
			len = 0;
		else
		{
			if (flag.prec < 0)
				len = max(arg.len, flag.width);
			else
				len = max(flag.width, min(arg.len, h_neg(flag.prec)));
		}
	}
	else
		len = max(arg.len, flag.width);
	return (max(len, 0));
}
