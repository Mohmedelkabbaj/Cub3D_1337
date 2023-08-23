/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:01:50 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/11/15 14:26:30 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s)
{
	char	*p;
	int		j;
	int		i;

	j = 0;
	i = 0;

	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		p[j++] = s[i++];
	if (s[i] == '\n')
		p[j++] = '\n';
	p[j] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;
	int 	j;

	j = 0;
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	p = malloc((ft_strlen(s1) - i + 1) * sizeof(char));
	if (!p)
		return (0);
	i++;
	while (s1[i])
		p[j++] = s1[i++];
	p[j] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdu(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = 0;
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
	{
		return (0);
	}
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
