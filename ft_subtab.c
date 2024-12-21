/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:24:09 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/24 19:22:23 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_subtab(void **tab, int start, int end)
{
	void	**subtab;
	int		i;

	if (!tab || start < 0 || end < 0 || start > end)
		return (NULL);
	subtab = malloc(sizeof(void *) * (end - start + 1));
	if (!subtab)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		subtab[i] = tab[start];
		start++;
		i++;
	}
	subtab[i] = NULL;
	return (subtab);
}
