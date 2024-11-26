/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:44:24 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/19 12:53:15 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tablen(void *tab)
{
	int		i;
	int		**ptr;

	i = 0;
	if (!tab)
		return (0);
	ptr = (int **)tab;
	while (*ptr && *ptr[i])
		i++;
	return (i);
}

void	ft_tabreverse(void *tab, int n)
{
	int		i;
	int		j;
	int		temp;
	int		**ptr;

	i = 0;
	if (!tab)
		return ;
	j = n - 1;
	ptr = (int **)tab;
	if (n == 0)
		j = ft_tablen(tab) - 1;
	while (i < j)
	{
		temp = *ptr[i];
		*ptr[i] = *ptr[j];
		*ptr[j] = temp;
		i++;
		j--;
	}
}

void	ft_strreverse(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	if (!str)
		return ;
	j = ft_strlen(str) - 1;
	while (i < j && str && str[i] && str[j])
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
