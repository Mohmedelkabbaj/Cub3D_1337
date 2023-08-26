/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:34 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/26 18:26:44 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdint.h>

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
	cub3d->map_2d = to_rectangle(cub3d->map_2d, tall_line(cub3d->map_2d));
	if (check_inside_map(cub3d->map_2d) == 1)
		return (1);
	return (0);
}