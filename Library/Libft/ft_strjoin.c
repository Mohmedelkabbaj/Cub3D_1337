/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:31:03 by hamaarou          #+#    #+#             */
/*   Updated: 2022/10/24 13:56:18 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;
	int		full_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(full_len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = 0;
	return (p);
}
