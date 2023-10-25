/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:38:46 by hamaarou          #+#    #+#             */
/*   Updated: 2023/10/25 16:25:20 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float    player_angel(char c)
{
    if (c == 'N')
        return (NO);
    else if (c == 'S')
        return (SO);
    else if (c == 'E')
        return (EA);
    else
        return (WE);
}

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
            {
                cub3d->player.rotation_angle = player_angel(cub3d->map_2d[cub3d->player.y][cub3d->player.x]);
                printf("%f\n", cub3d->player.rotation_angle);
                cub3d->player.x = cub3d->player.x * 32 + 16;
                cub3d->player.y = cub3d->player.y * 32 + 16;
                return ;
            }
            cub3d->player.x++;
        }
        cub3d->player.y++;
    }

    printf("Error\nNo player position found\n");
}
