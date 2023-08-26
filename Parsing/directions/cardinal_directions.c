/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:02:21 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/26 20:39:43 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	cardinal_direction(char *line)
{
	line = ft_strtrim(line, " ");
	if ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'E' && line[1] == 'A')
		|| (line[0] == 'W' && line[1] == 'E'))
		return (free(line), 1);
	return (free(line), 0);
}

int	check_textures(t_cub3d *cub3d)
{
	if (cub3d->parse_direct.north_texture == NULL ||
		cub3d->parse_direct.south_texture == NULL ||
		cub3d->parse_direct.east_texture == NULL ||
		cub3d->parse_direct.west_texture == NULL)
		return (ft_putendl_fd("Error\nMissing textures", 2), 1);
	return (0);
}