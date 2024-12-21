/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:18:14 by nbasheer          #+#    #+#             */
/*   Updated: 2024/12/17 11:47:22 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_pop_index(char **tab, int index)
{
	char	**new_tab;
	int		i;
	int		j;

	if (!tab || index < 0 || index >= ft_tablen(tab))
		return (tab);
	new_tab = (char **)malloc(sizeof(char *) * ft_tablen(tab));
	if (!new_tab)
		return (NULL);
	i = -1;
	j = -1;
	while (tab[++i])
	{
		if (i == index)
			continue ;
		new_tab[++j] = ft_strdup(tab[i]);
	}
	new_tab[++j] = NULL;
	ft_tabfree(tab);
	return (new_tab);
}
