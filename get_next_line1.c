/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alancel <alancel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:14:58 by alancel           #+#    #+#             */
/*   Updated: 2020/11/02 22:47:54 by alancel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*write_line(char *remainder)
{
	int		len;
	char	*line;

	len = 0;
	if (!remainder)
		return (0);
	while (remainder[len] != '\0' && remainder[len] != '\n')
		len++;
	if (!(line = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (remainder[len] != '\0' && remainder[len] != '\n')
	{
		line[len] = remainder[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*write_ost(char *remainder)
{
	char	*new;
	int		del;
	int		i;

	del = 0;
	i = 0;
	if (!remainder)
		return (0);
	while (remainder[del] != '\0' && remainder[del] != '\n')
		del++;
	if (!remainder[del])
	{
		free(remainder);
		return (0);
	}
	if (!(new = malloc(sizeof(char) * ((ft_strlen(remainder) - del) + 1))))
		return (0);
	del++;
	while (remainder[del])
		new[i++] = remainder[del++];
	new[i] = '\0';
	free(remainder);
	return (new);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*remainder;
	int				file;

	file = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ost_n(remainder) && file)
	{
		if ((file = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[file] = '\0';
		CHECK((remainder = ft_strjoin(remainder, buf)));
	}
	free(buf);
	CHECK((*line = write_line(remainder)));
	remainder = write_ost(remainder);
	if (file == 0)
		return (0);
	return (1);
}
	
