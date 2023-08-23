/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:43:02 by hamaarou          #+#    #+#             */
/*   Updated: 2022/10/23 14:12:11 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int j)
{
	int		i;
	char	c;
	int		len;

	i = 0;
	c = (char)j;
	len = ft_strlen(str);
	if (c == '\0')
		return (&str[len]);
	while (i < len)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}
