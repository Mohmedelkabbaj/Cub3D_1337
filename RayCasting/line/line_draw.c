/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:38:47 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/03 22:02:30 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void cast_ray(double ray_angle, t_mlx *mlx, int color)
{
	double player_x = mlx->cub3d.player.x;
	double player_y = mlx->cub3d.player.y;
	double ray_x = player_x;
	double ray_y = player_y;

	while (1)
	{
		ray_x += cos(ray_angle);
		ray_y += sin(ray_angle);
		if (check_wall(mlx, ray_x, ray_y))
			break;
		my_mlx_pixel_put(&mlx->data, SCALE_FACTOR * (double)ray_x, SCALE_FACTOR * (double)ray_y, color);
	}
}


void ray(t_mlx *mlx, int color)
{
	double	ray_angle;
	double	ray_increment;
	int		i;
	
	ray_angle = mlx->cub3d.player.rotation_angle - (FOV_ANGLE / 2);
	ray_increment = FOV_ANGLE / NUM_RAYS;
	i = 0;
	while (i < NUM_RAYS)
	{
		cast_ray(ray_angle, mlx, color);
		ray_angle += ray_increment;
		i++;
	}
}
