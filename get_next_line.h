/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alancel <alancel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:05:51 by alancel           #+#    #+#             */
/*   Updated: 2020/11/05 19:17:12 by alancel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int					get_next_line(int fd, char **line);
int					has_return(char *str);
size_t				ft_strlen(const char *s);
char				*ft_str_join(const char *s1, const char *s2);
#endif
