/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:03:48 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 14:58:01 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_textures(t_cub3d *cub3d)
{
    if (cub3d->parse_direct.north_texture != NULL)
        free(cub3d->parse_direct.north_texture);
    if (cub3d->parse_direct.south_texture!= NULL)
        free(cub3d->parse_direct.south_texture);
    if (cub3d->parse_direct.east_texture != NULL)
        free(cub3d->parse_direct.east_texture);
    if (cub3d->parse_direct.west_texture != NULL)
        free(cub3d->parse_direct.west_texture);
    
}