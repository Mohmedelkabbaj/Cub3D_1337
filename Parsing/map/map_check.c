/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:34 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/26 13:25:29 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdint.h>

int	is_map(char *line)
{
	int	i;

	i = -1;
	while(line[++i])
		if (line[i] == '1' || line[i] == '0')
			return (1);
	return (0);
}

size_t	tall_line(char **map)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = -1;
	max = 0;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (max < ft_strlen(map[i]))
				max = ft_strlen(map[i]);
		}
	}
	return (max);
}

char	*get_line(char *line, size_t max)
{
	char	*new_line;
	size_t	i;
	
	new_line = ft_calloc_char(1,(max + 1), '.');
	i = 0;
	while(i < max)
	{
		if (ft_strlen(line) > i && (line[i] == '1' || line[i] == '0'))
			new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	**to_rectangle(char **map, size_t line_length)
{
	int		i;
	char	*tmp;

	i = -1;
	while (map[++i])
	{
		tmp = ft_strdup(map[i]);
		map[i] = get_line(tmp, line_length);
		free(tmp);
	}
	return (map);
}

int	map_check(t_cub3d *cub3d)
{
	if (is_surrounded(cub3d) == 1)
		return (1);
	



	return (0);
}