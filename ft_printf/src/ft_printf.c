/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:34:27 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/04 16:00:53 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	if (!format)
		return (-1);
	if (format[0] == '\0')
		return (0);
	ret = 0;
	va_start(args, format);
	if (print(format, args, &ret) == -1)
		return (-1);
	va_end(args);
	return (ret);
}
