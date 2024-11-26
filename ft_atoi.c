/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:24:05 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/05 18:17:29 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		s;
	int		res;

	if (!str)
		return (0);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	i = 0;
	s = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			s *= -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (((long) res * 10 + (str[i] - '0')) > 2147483647)
			return (0);
		else
			res = (res * 10) + (str[i++] - '0');
	}
	return (res * s);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[++j] != '\0')
			if (base[j] == base[i])
				return (0);
	}
	return (i);
}

int	is_in_base(char str, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
		if (base[i] == str)
			return (i);
	return (-1);
}

long long	ft_atoi_base(char *str, char *base)
{
	int			s;
	long long	res;
	int			i;
	int			len_base;

	s = 1;
	res = 0;
	i = 0;
	len_base = check_base(base);
	if (base[0] != '\0' && base[1] != '\0' && len_base > 1)
	{
		while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
		while (str[i] && (str[i] == '-' || str[i] == '+'))
			if (str[i++] == '-')
				s *= (-1);
		while (str[i] && is_in_base(str[i], base) != -1)
			res = (res * len_base) + is_in_base(str[i++], base);
		return (res * s);
	}
	return (0);
}
