/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alancel <alancel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:42:25 by alancel           #+#    #+#             */
/*   Updated: 2020/11/02 21:49:13 by alancel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1))))
		return (NULL);
	size = ft_strlen(s1);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[i + size] = s2[i];
	str[i + size] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*str_copy;
	size_t	i;

	i = 0;
	if (!(str_copy = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int sym)
{
	while (*str)
	{
		if (*str++ == (char)sym)
			return ((char *)str - 1);
	}
	if (sym == '\0')
		return ((char *)str);
	return (NULL);
}
char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
	{
		*(s + i) = '\0';
		i++;
	}
}
void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}
void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}