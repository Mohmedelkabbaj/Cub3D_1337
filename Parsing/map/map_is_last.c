/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:10:02 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 11:38:12 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	textures_is_fill(t_cub3d *cub3d)
{
	if (cub3d->parse_direct.north_texture == NULL)
		return (0);
	if (cub3d->parse_direct.south_texture == NULL)
		return (0);
	if (cub3d->parse_direct.east_texture == NULL)
		return (0);
	if (cub3d->parse_direct.west_texture == NULL)
		return (0);
	return (1);
}

int	floor_ceiling_is_color(t_cub3d *cub3d)
{
	if (cub3d->floor.r == -1 || cub3d->floor.g == -1 || cub3d->floor.b == -1)
		return (0);
	if (cub3d->ceiling.r == -1 || cub3d->ceiling.g == -1 || cub3d->ceiling.b == -1)
		return (0);
	return (1);
}

int	is_map_last(t_cub3d *cub3d)
{
	if (textures_is_fill(cub3d) == 0 || floor_ceiling_is_color(cub3d) == 0)
		return (0);
	return (1);
}
