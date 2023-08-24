/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:15:44 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/24 12:15:49 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures(t_cub3d *cub3d)
{
	cub3d->parse_direct.north_texture = NULL;
	cub3d->parse_direct.south_texture = NULL;
	cub3d->parse_direct.east_texture = NULL;
	cub3d->parse_direct.west_texture = NULL;
}

void init_rgb(t_cub3d *cub3d)
{
	cub3d->floor.r = -1;
	cub3d->floor.g = -1;
	cub3d->floor.b = -1;
	cub3d->ceiling.r = -1;
	cub3d->ceiling.g = -1;
	cub3d->ceiling.b = -1;
}
