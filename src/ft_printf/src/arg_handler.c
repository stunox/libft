/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:49 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/07 16:59:49 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

t_arg	get_strs_arg(t_flags flag, va_list args)
{
	t_arg	arg;

	if (flag.type == 'c')
	{
		arg.c = va_arg(args, int);
		arg.len = 1;
	}
	else if (flag.type == 's')
	{
		arg.str = ft_strdup(va_arg(args, char *));
		if (!arg.str && ((flag.width > 5 && flag.prec < 0)
				|| flag.prec > 5 || flag.prec == -1))
			arg.str = ft_replace(arg.str, ft_strdup("(null)"));
		if (flag.prec > 0 && ft_strcmp(arg.str, "(null)") != 0)
		{
			arg.str = ft_replace(arg.str, ft_substr(arg.str, 0, flag.prec));
		}
		arg.len = ft_strlen(arg.str);
	}
	else if (flag.type == 'p')
	{
		arg.arg = va_arg(args, void *);
		arg.len = (nbrlen_hex((unsigned long long)arg.arg) + 2);
	}
	return (arg);
}

t_arg	get_numbers_arg(t_flags flag, va_list args)
{
	t_arg	arg;

	if (flag.type == 'd' || flag.type == 'i')
	{
		arg.nbr = va_arg(args, int);
		arg.len = nbrlen(arg.nbr);
	}
	else if (flag.type == 'u')
	{
		arg.nbr = va_arg(args, unsigned int);
		arg.len = nbrlen(arg.nbr);
	}
	else if (flag.type == 'x' || flag.type == 'X')
	{
		arg.nbr = va_arg(args, unsigned int);
		arg.len = nbrlen_hex((unsigned long long)arg.nbr);
		if (flag.hash && arg.nbr != 0)
			arg.len += 2;
		arg.additional = flag.type;
	}
	return (arg);
}

t_arg	get_arg(t_flags flag, va_list args)
{
	t_arg	arg;

	if (ft_strchr("csp", flag.type) != NULL)
		arg = get_strs_arg(flag, args);
	else if (ft_strchr("diuxX", flag.type) != NULL)
		arg = get_numbers_arg(flag, args);
	else
	{
		arg.len = 1;
		arg.c = '%';
	}
	return (arg);
}
