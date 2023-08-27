/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:38:35 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 18:45:37 by hamaarou         ###   ########.fr       */
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
	char *trime_line;
	char *tmp;
	i = 0;
	
	trime_line = ft_strtrim(line, " ");
	tmp = ft_strtrim(trime_line, "\n");
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]) == 0)
		{
			free(trime_line);
			free(tmp);
			return (1);
		}
		i++;
	}
	free(trime_line);
	free(tmp);
	return (0);
}