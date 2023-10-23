/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:10:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/10/23 15:13:49 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

 void	map_height(t_cub3d *cub3d)
{
	cub3d->map_height = 0;
	while (cub3d->map_2d[cub3d->map_height])
		cub3d->map_height++;
}

void	map_width(t_cub3d *cub3d)
{
	cub3d->map_width = 0;
	while (cub3d->map_2d[0][cub3d->map_width])
		cub3d->map_width++;	
}

int	first_last_lines(char *line)
{
	int	i;
	char *trimed_line;
	i = 0;
	
	trimed_line = ft_strtrim(line, " ");
	while (trimed_line[i])
	{
		if (trimed_line[i] != '1' && trimed_line[i] != ' ')
			return (free(trimed_line), 0);
		i++;
	}
	free(trimed_line);
	return (1);
}

int first_last_column(char *line)
{
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
    return (1);
}