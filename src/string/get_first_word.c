/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:52:44 by nbasheer          #+#    #+#             */
/*   Updated: 2024/12/11 11:53:20 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_first_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (str[++i] && !ft_isprint(str[i]) && !ft_isspace(str[i]))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}
