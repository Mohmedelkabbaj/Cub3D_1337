/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:11:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/10/30 18:25:41 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int check_wall(t_mlx *mlx, double x, double y)
{
	if (x < 0 || y < 0 || x > (mlx->cub3d.map.x * TILE_SIZE) || y > mlx->cub3d.map.y * TILE_SIZE)
		return (0);
	if (is_wall(mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)]))
		return (0);
	return (1);
}