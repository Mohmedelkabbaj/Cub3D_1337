/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:34:30 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/11/15 14:23:20 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (0);
	j = 0;
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	free(s1);
	return (p);
}

char	*line(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(str, '\n') == -1 && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			if (str)
			 	free (str);
			return (NULL);

		}
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);

	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = line(fd,str);

	if (str == NULL)
		return (0);
	tmp = ft_substr(str);
	str = ft_strdup(str);
	return (tmp);
}
