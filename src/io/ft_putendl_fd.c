/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:45:40 by nbasheer          #+#    #+#             */
/*   Updated: 2024/10/12 20:45:40 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd, int to_free)
{
	if (!s)
		return ;
	if (fd < 0)
		fd = 1;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	if (to_free)
		free(s);
}
