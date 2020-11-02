/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alancel <alancel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:14:58 by alancel           #+#    #+#             */
/*   Updated: 2020/11/02 22:31:13 by alancel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *check_reminder(char *remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if(remainder)
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strclr(remainder);
		}
	else
		*line = ft_strnew(1);
	return(p_n);
}

int		get_next_line(int fd, char **line)
{
	int byte_was_read;
	char buff[BUFFER_SIZE + 1];
	char *p_n;
	static char *reminder;
	char *tmp;
	
	
	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	p_n = check_reminder(reminder, line);
	while (!p_n &&(byte_was_read = read(fd, buff, BUFFER_SIZE)))
	{
		buff[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buff, '\n')))
		{
			*p_n = '\0';
			p_n++;
			reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return(byte_was_read || ft_strlen(*line)) ? 1 : 0;
}
