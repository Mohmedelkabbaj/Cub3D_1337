/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:47:14 by hamaarou          #+#    #+#             */
/*   Updated: 2022/10/23 14:11:46 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	k = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (k[i] == (unsigned char)c)
			return (&k[i]);
		i++;
	}
	return (0);
}
