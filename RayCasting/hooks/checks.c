/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:11:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/03 19:15:02 by hamaarou         ###   ########.fr       */
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

int check_wall(t_mlx *mlx, float x, float y)
{
	if (x <= 0 || y <= 0 || x >= mlx->cub3d.map.x * TILE_SIZE || y >= mlx->cub3d.map.y * TILE_SIZE )
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)((y - 1) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)((y + 1) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x - 1) / TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x + 1) / TILE_SIZE)] == '1')
		return (1);
	return (0);
}