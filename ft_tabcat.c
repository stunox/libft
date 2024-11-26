/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:02:35 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/24 19:10:46 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcat(char **tab1, char **tab2)
{
	char	**res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	res = (char **)malloc((ft_tablen(tab1) + ft_tablen(tab2) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (tab1[++i])
		res[i] = ft_strdup(tab1[i]);
	while (tab2[++j])
		res[i + j] = ft_strdup(tab2[j]);
	res[i + j] = NULL;
	return (res);
}
