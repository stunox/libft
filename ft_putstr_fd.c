/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:44:28 by nbasheer          #+#    #+#             */
/*   Updated: 2024/10/12 20:44:28 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd, int to_free)
{
	if (!s)
		return ;
	if (fd < 0)
		fd = 1;
	write(fd, s, ft_strlen(s));
	if (to_free)
		free(s);
}
