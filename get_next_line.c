/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:20:06 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/20 16:20:06 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	parse_line(char *buf, char **line, char **temp, int *nb)
{
	*line = add_str(*line, add_str(ft_substr(buf, 0, nb[0]), "\n", 0), 1);
	free(*temp);
	if (nb[0] == nb[1] - 1)
		*temp = NULL;
	else
		*temp = ft_strdup(&buf[nb[0] + 1]);
	return (1);
}

static int	get_line(char *buf, char **temp, char **line, int n)
{
	int	*i;

	i = (int [3]){0, ft_strlen(*line), 0};
	while (line && *line && i[0] < i[1] && (*line)[i[0]] != '\n')
		i[0]++;
	if (i[0] < i[1] && (*line)[i[0]] == '\n')
	{
		*temp = add_str(ft_strdup(&(*line)[i[0] + 1]), *temp, 1);
		(*line)[i[0] + 1] = '\0';
		return (1);
	}
	while (i[2] < n && buf && buf[i[2]] != '\n')
		i[2]++;
	if (i[2] == n && buf && buf[i[2]] != '\n')
		*line = add_str(*line, buf, 0);
	else if (buf)
		return (parse_line(buf, line, temp, (int [2]){i[2], n}));
	return (0);
}

static void	load_temp(char **temp, char **line)
{
	char	*new_temp;
	int		i;

	i = 0;
	if (!*temp)
		return ;
	while ((*temp)[i] && (*temp)[i] != '\n')
		i++;
	if ((*temp)[i] == '\n')
	{
		*line = ft_substr(*temp, 0, i + 1);
		new_temp = ft_strdup(&(*temp)[i + 1]);
		free(*temp);
		*temp = new_temp;
	}
	else
	{
		*line = ft_strdup(*temp);
		free(*temp);
		*temp = NULL;
	}
}

char	*get_next_line(int fd, int nl)
{
	char		*line;
	static char	*temp;
	char		buf[BUFFER_SIZE + 1];
	int			n;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	load_temp(&temp, &line);
	n = BUFFER_SIZE;
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE * (temp == NULL));
		if (n <= 0 || buf[0] == '\0')
			break ;
		buf[n] = '\0';
		if (get_line(buf, &temp, &line, n))
			break ;
	}
	if (line && *line)
		return (ft_replace(line, ft_strtrim(line, (char [2]){'\n' * nl, '\0'})));
	return (NULL);
}
