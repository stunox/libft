/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:56 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/07 16:59:56 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_additional_flags(const char *format, t_flags *flag, int *i)
{
	if (format[*i] == '0')
		flag->zero = 1;
	else if (format[*i] == '-')
	{
		flag->minus = 1;
		flag->zero = 0;
	}
	else if (format[*i] == ' ')
		flag->space = 1;
	else if (format[*i] == '+')
	{
		flag->plus = 1;
		flag->space = 0;
	}
	else if (format[*i] == '#')
		flag->hash = 1;
	(*i)++;
}

static void	handle_flag(t_flags *flag, const char *format, int i)
{
	int	start;
	int	x;

	start = i;
	x = 0;
	while (ft_strchr("-0 +#", format[i]) != NULL)
		handle_additional_flags(format, flag, &i);
	while ((format[i]) && ft_isdigit(format[i]) && ++x)
		flag->width = (flag->width * 10) + (format[i++] - '0');
	if (x == 0)
		flag->width = -1;
	x = 0;
	if (format[i] == '.')
		while ((format[i + ++x]) && ft_isdigit(format[i + x]))
			flag->prec = (flag->prec * 10) + (format[i + x] - '0');
	if (x == 0)
		flag->prec = -1;
	flag->len = ((i + x) - start) + 2;
	flag->type = format[i + x];
}

void	init_flag(t_flags *flag, const char *format, int i)
{
	flag->width = 0;
	flag->prec = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->hash = 0;
	handle_flag(flag, format, i);
}
