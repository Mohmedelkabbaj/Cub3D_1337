/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:08:06 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 18:55:04 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_surrounded(t_cub3d *cub3d)
{
	int		i;
	char	*line;

	i = 0;
	map_height(cub3d);
	line = ft_strtrim(cub3d->map_2d[i], " ");
	while(cub3d->map_2d[i])
	{
		if (i == 0 || i == cub3d->map_height - 1)
		{
			if (first_last_lines(line) == 0)
				return (free(line), 1);
		}
		else
		{
			if (first_last_column(line) == 0)
				return (free(line), 1);
		}
		i++;
	}
	return (free(line), 0);
}