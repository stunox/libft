/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:24:59 by nbasheer          #+#    #+#             */
/*   Updated: 2024/10/13 11:24:59 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_fd_temp
{
	int					fd;
	char				*t;
	struct s_fd_temp	*next;
}		t_fd_temp;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*add_str(char *str, char *buffer, int to_free);
int			init_temp(t_fd_temp **new_temp, int i, int fd);
char		*get_next_line(int fd, int nl);

#endif // GET_NEXT_LINE_H 