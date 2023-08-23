/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:48:02 by hamaarou          #+#    #+#             */
/*   Updated: 2022/10/23 14:12:34 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack_new;

	haystack_new = (char *)haystack;
	i = 0;
	if (!needle[0])
		return (haystack_new);
	if (haystack_new == NULL && len == 0)
		return (NULL);
	while (haystack_new[i] && i < len)
	{
		j = 0;
		if (haystack_new[i] == needle[j])
		{
			while (haystack_new[i + j] && needle[j] && (i + j) < len
				&& needle[j] == haystack_new[i + j])
				j++;
			if (!needle[j])
				return (&haystack_new[i]);
		}
		i++;
	}
	return (0);
}
