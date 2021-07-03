/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:43:14 by mderri            #+#    #+#             */
/*   Updated: 2021/07/03 01:42:35 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	char		*buff;
	static char *mind[4864];
	int			i;
	int			j;

	i = 0;
	j = 0;
	buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1);
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!mind[fd])
		mind[fd] = ft_strnew(0);
	while (!(ft_strchr(mind[fd], '\n')) && (i = read(fd, buff, BUFF_SIZE)))
	{
		buff[i] = '\0';
		mind[fd] = ft_strjoin(mind[fd], buff);
	}
	free(buff);
	while (mind[fd][j] != '\0' && mind[fd][j] != '\n')
		j++;
	*line = ft_strsub(mind[fd], 0, j);
	if (i == 0 && ft_strlen(mind[fd]) == 0)
		return (0);
	mind[fd] = ft_strdup(mind[fd] + j + 1);
	return (1);
}

