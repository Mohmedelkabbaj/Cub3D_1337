/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:31:03 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/24 15:36:10 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_utils(char *s1)
{
	s1 = (char *)malloc(sizeof(char) * 1);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;
	int		full_len;

	i = 0;
	j = 0;
	if (!s1)
		s1 = join_utils(s1);
	if (!s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(full_len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = 0;
	free(s1);
	return (p);
}
