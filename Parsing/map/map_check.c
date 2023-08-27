/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:34 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 17:06:37 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdint.h>

int	check_newline(char *map_1d)
{
	int	i;
	
	i = -1;
	while(map_1d[++i])
		if (map_1d[i] == '\n' && map_1d[i + 1] == '\n')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_strlen_doublepointer(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char **ft_strdup_doublepointer(char **s1)
{
	char	**p;
	int		i;

	i = 0;
	p = (char **)malloc(sizeof(char *) * (ft_strlen_doublepointer(s1) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = ft_strdup(s1[i]);
		i++;
	}
	p[i] = NULL;
	return (p);
}

int	check_inside_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if (map[i - 1][j] == '$' || map[i + 1][j] == '$'
					|| map[i][j - 1] == '$' || map[i][j + 1] == '$')
					return (1);
			}
		}
	}
	return (0);
}

int	map_check(t_cub3d *cub3d)
{
	cub3d->map_2d = ft_split(cub3d->map_1d, '\n');
	cub3d->map_2d = to_rectangle(cub3d->map_2d, tall_line(cub3d->map_2d));
	if (check_inside_map(cub3d->map_2d) == 1)
		return (1);
	return (0);
}
