/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:38:46 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/28 09:46:28 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    get_p_position(t_cub3d *cub3d)
{
    cub3d->player.y = 0;
    while (cub3d->map_2d[cub3d->player.y])
    {
        cub3d->player.x = 0;
        while(cub3d->map_2d[cub3d->player.y][cub3d->player.x])
        {
            if (cub3d->map_2d[cub3d->player.y][cub3d->player.x] == 'S'
                || cub3d->map_2d[cub3d->player.y][cub3d->player.x] == 'N'
                || cub3d->map_2d[cub3d->player.y][cub3d->player.x] == 'E'
                || cub3d->map_2d[cub3d->player.y][cub3d->player.x] == 'W')
                return ;
            cub3d->player.x++;
        }
        cub3d->player.y++;
    }
}
