/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alancel <alancel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:05:51 by alancel           #+#    #+#             */
/*   Updated: 2020/11/02 21:49:21 by alancel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5000
#endif

typedef struct		s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}					t_arr;

t_arr				*ft_newlist(const int fd);
char				*checkrest(char **p_n, char *rest);
int					get_line(const int fd, char **line, char *rest);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int 	ft_endl_check(char *str);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *str, int sym);
char *ft_strcpy(char *dest, char *src);
void	ft_strclr(char *s);
char	*ft_strcat(char *restrict str1, const char *restrict str2);
void	ft_strdel(char **as);
void	ft_memdel(void **ap);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
#endif