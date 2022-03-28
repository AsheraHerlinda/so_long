/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2021/12/09 20:44:50 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!line)
	{
		line = (char *)malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	if (!line && !buf)
		return (NULL);
	ptr = (char *) malloc(ft_strlen(line) + ft_strlen(buf) + 1);
	if (!ptr)
		return (NULL);
	if (line)
		while (line[++i] != '\0')
			ptr[i] = line[i];
	while (buf[j] != '\0')
		ptr[i++] = buf[j++];
	ptr[ft_strlen(line) + ft_strlen(buf)] = '\0';
	free(line);
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}
