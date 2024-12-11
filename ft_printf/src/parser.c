/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:00:04 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/07 17:00:04 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_flags f, t_arg *arg)
{
	if (arg->arg == NULL)
		arg->len = 5;
	if (!f.minus && f.width > 0)
		ft_putstr(repeat_char(' ', f.width - arg->len), 1);
	if (arg->arg == NULL)
		ft_putstr("(nil)", 0);
	else
	{
		ft_putstr("0x", 0);
		ft_putnbr_hex((unsigned long long)arg->arg, 'x');
	}
	if (f.minus && f.width > 0)
		ft_putstr(repeat_char(' ', f.width - arg->len), 1);
}

void	print_strs(t_flags f, t_arg *arg)
{
	int	space;

	if (f.type == 'c')
	{
		if (!f.minus && f.width > 0)
			ft_putstr(repeat_char(' ', f.width - 1), 1);
		ft_putchar_fd(arg->c, 1);
		if (f.minus && f.width > 0)
			ft_putstr(repeat_char(' ', f.width - 1), 1);
	}
	else if (f.type == 's')
	{
		space = max(f.width - min(f.width, min(arg->len, h_neg(f.prec))), 0);
		if (!f.minus && space > 0)
			ft_putstr(repeat_char(' ', space), 1);
		if (f.prec != 0)
			ft_putstr(arg->str, 0);
		free(arg->str);
		if (f.minus && space > 0)
			ft_putstr(repeat_char(' ', space), 1);
	}
	else
		print_pointer(f, arg);
}

void	print_numbers(t_flags f, t_arg *a, int z, int sp)
{
	if (f.type == 'd' || f.type == 'i')
	{
		if (f.prec == 0)
			sp = sp + a->len - max(a->len, max(f.prec, 0));
		if (!f.minus && f.width > 0 && (!f.zero || f.prec >= 0))
			ft_putstr(repeat_char(' ', sp), 1);
		if (a->nbr < 0)
			ft_putchar_fd('-', 1);
		else if (f.plus)
			ft_putchar_fd('+', 1);
		else if (f.space)
			ft_putchar_fd(' ', 1);
		if (f.zero || f.prec > 0)
			ft_putstr(repeat_char('0', z), 1);
		if (a->nbr < 0)
			ft_putstr(ft_u_itoa(-a->nbr), 1);
		else if (f.prec != 0 || a->nbr != 0)
			ft_putnbr(a->nbr);
		if (f.minus && f.width > 0 && (!f.zero || f.prec >= 0))
			ft_putstr(repeat_char(' ', sp), 1);
	}
	else
		print_hex(f, a, z, sp);
}

void	print_hex(t_flags f, t_arg *arg, int zeros, int sp)
{
	if (f.type == 'u')
	{
		if (!f.minus && f.width > 0)
			ft_putstr(repeat_char(' ', sp), 1);
		if (f.zero || f.prec > 0)
			ft_putstr(repeat_char('0', zeros), 1);
		if (f.prec != 0 || arg->nbr != 0)
			put_u_nbr((unsigned int)arg->nbr);
		if (f.minus && f.width > 0)
			ft_putstr(repeat_char(' ', sp), 1);
	}
	else if (f.type == 'x' || f.type == 'X')
	{
		if (!f.minus && f.width > 0)
			ft_putstr(repeat_char(' ', sp), 1);
		if (f.zero || f.prec > 0)
			ft_putstr(repeat_char('0', zeros), 1);
		if (f.hash && arg->nbr != 0)
			ft_putstr(ft_stradd("0", f.type), 1);
		if (f.prec != 0 || arg->nbr != 0)
			ft_putnbr_hex((unsigned long long)arg->nbr, arg->additional);
		if (f.minus && f.width > 0)
			ft_putstr(repeat_char(' ', sp), 1);
	}
}

void	print_conversion(t_flags f, t_arg a, int *ret)
{
	int	len;
	int	sp;
	int	z;

	if (ft_strchr("csp", f.type) != NULL)
		print_strs(f, &a);
	else if (ft_strchr("diuxX", f.type) != NULL)
	{
		z = max(f.prec, a.len - (a.nbr < 0)) - a.len + (a.nbr < 0);
		if (f.zero && f.prec < 0)
			z = f.width - a.len;
		sp = f.width - z - a.len + (!(a.nbr || f.prec));
		print_numbers(f, &a, z, sp);
	}
	else if (f.type == '%')
		ft_putchar_fd('%', 1);
	if (f.type == '%')
		len = 1;
	else
		len = get_len(f, a);
	*ret += len;
}
