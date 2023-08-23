/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:38:35 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/23 19:50:39 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	comma_check(char *line)
{
	int		i;
	int		comma;
	int		comma2;
	
	i = 0;
	comma = 0;
	comma2 = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			comma++;
			if (line[i + 1] == ',')
				comma2++;
		}
		i++;
	}
	if (comma != 2 || comma2 != 0)
		return (1);
	return (0);
}

int	result_length(char *line)
{
	int	i;
	int	count;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || ft_isalpha(line[i]) || line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int check_isdigit(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}