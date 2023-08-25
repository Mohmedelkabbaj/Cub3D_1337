/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:10:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/25 17:25:48 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

 void	map_height(t_cub3d *cub3d)
{
	cub3d->map_height = 0;
	while (cub3d->map_2d[cub3d->map_height])
		cub3d->map_height++;
}

int	first_last_lines(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int first_last_column(char *line)
{
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
    return (1);
}