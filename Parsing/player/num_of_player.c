/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_of_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:51:41 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 18:53:54 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int num_of_player(t_cub3d *cub3d)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while(cub3d->map_2d[++i])
    {
        if (ft_strchr(cub3d->map_2d[i], 'N') || ft_strchr(cub3d->map_2d[i], 'S')
            || ft_strchr(cub3d->map_2d[i], 'E') || ft_strchr(cub3d->map_2d[i], 'W'))
            count++;
    }
    if (count != 1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
