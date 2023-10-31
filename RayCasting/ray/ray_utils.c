/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:56:47 by hamaarou          #+#    #+#             */
/*   Updated: 2023/10/31 16:03:59 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// a function that draws a line from (x0, y0) to (x1, y1)

void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
	int delta_x = x1 - x0;
	int delta_y = y1 - y0;
	int step_x = 1;
	int step_y = 1;
	if (delta_x < 0)
	{
		step_x = -1;
		delta_x *= -1;
	}
	if (delta_y < 0)
	{
		step_y = -1;
		delta_y *= -1;
	}
	int max_delta = (delta_x > delta_y) ? delta_x : delta_y;
	int x = x0;
	int y = y0;
	int i = 0;
	while (i <= max_delta && x / 32 > 0 && y / 32 > 0 && x / 32 < 10 && y / 32 < 14)
	{
		my_mlx_pixel_put(&mlx->data, x, y, color);
		x += step_x;
		y += step_y;
		i++;
	}
}

void	ft_horizontal_up(t_mlx *mlx)
{
	double a;
	double b;

	mlx->h_y = floor(mlx->cub3d.player.y / TILE_SIZE) * TILE_SIZE;
	mlx->h_x = mlx->h_x + ((mlx->h_x - mlx->h_y) / tan(mlx->cub3d.player.rotation_angle));
	if(mlx->h_x >= mlx->cub3d.map.x || mlx->h_x < 0)
	{
		mlx->cub3d.map_width = mlx->cub3d.map.x;
		mlx->cub3d.map_height = mlx->cub3d.map.y;
		return;
	}
	if(check_wall(mlx, mlx->h_x, mlx->h_y))
	{
		return;
	}
	a = mlx->h_x;
	b = mlx->h_y;
	mlx->h_y -= TILE_SIZE;
	mlx->h_x -= (b - mlx->h_y / tan(mlx->cub3d.player.rotation_angle));
	b = mlx->h_y - a;
	while (mlx->h_y > 0 && mlx->h_x < mlx->cub3d.map_width && !check_wall(mlx, mlx->h_x, mlx->h_y))
	{
		mlx->h_y -= TILE_SIZE;
		mlx->h_x -= (b);
	}
	// // printf("%f %f \n", mlx->h_y / 32, mlx->h_x /32);
	// if(check_wall(mlx, mlx->h_x, mlx->h_y))
	// {
	// 	mlx->h_x -= (TILE_SIZE / tan(mlx->cub3d.player.rotation_angle));
	// 	mlx->h_y -= TILE_SIZE;
	// }
}

void	ft_horizontal_down(t_mlx *mlx)
{
	mlx->h_y = floor(mlx->cub3d.player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE - 1;
	mlx->h_x = mlx->h_y / tan(mlx->cub3d.player.rotation_angle);
	// printf("%f %f \n", mlx->h_y / 32, mlx->h_x /32);
	
	while (check_wall(mlx, mlx->h_x, mlx->h_y))
	{
		mlx->h_x += (TILE_SIZE / tan(mlx->cub3d.player.rotation_angle));
		mlx->h_y += TILE_SIZE;
	}
}

void	ft_up_right(t_mlx *mlx)
{
	mlx->v_x = floor(mlx->cub3d.player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	mlx->v_y =  (mlx->v_x - mlx->cub3d.player.x) * tan(mlx->cub3d.player.rotation_angle);
	while (check_wall(mlx, mlx->v_x, mlx->v_y))
	{
		mlx->v_x += TILE_SIZE;
		mlx->v_y += (TILE_SIZE * tan(mlx->cub3d.player.rotation_angle));
	}
}

void	ft_up_left(t_mlx *mlx)
{
	mlx->v_x = floor(mlx->cub3d.player.x / TILE_SIZE) * TILE_SIZE;
	mlx->v_y =  mlx->v_x * tan(mlx->cub3d.player.rotation_angle);
	while (check_wall(mlx, mlx->v_x, mlx->v_y))
	{
		mlx->v_x -= TILE_SIZE;
		mlx->v_y -= (TILE_SIZE * tan(mlx->cub3d.player.rotation_angle));
	}
}

void	ft_look_up(t_mlx *mlx)
{
	if (cos(mlx->cub3d.player.rotation_angle) >= 0)
		ft_up_right(mlx);
	else
		ft_up_left(mlx);
	
	ft_horizontal_up(mlx);
	
}

void	ft_down_right(t_mlx *mlx)
{
	mlx->v_x = floor(mlx->cub3d.player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	mlx->v_y = mlx->v_x * tan(mlx->cub3d.player.rotation_angle);
	while (check_wall(mlx, mlx->v_x, mlx->v_y))
	{
		mlx->v_x += TILE_SIZE;
		mlx->v_y -= (TILE_SIZE * tan(mlx->cub3d.player.rotation_angle));
	}
}

void	ft_down_left(t_mlx *mlx)
{
	mlx->v_x = floor(mlx->cub3d.player.x / TILE_SIZE) * TILE_SIZE;
	mlx->v_y = mlx->v_x * tan(mlx->cub3d.player.rotation_angle);
	while (check_wall(mlx, mlx->v_x, mlx->v_y))
	{
		mlx->v_x -= TILE_SIZE;
		mlx->v_y += (TILE_SIZE * tan(mlx->cub3d.player.rotation_angle));
	}
}

void	ft_look_down(t_mlx *mlx)
{
	if (cos(mlx->cub3d.player.rotation_angle) >= 0)
		ft_down_right(mlx);
	else
		ft_down_left(mlx);
	ft_horizontal_down(mlx);
}

// a function that compares the length of two rays and returns the shortest one

int	ft_compare(t_mlx *mlx)
{
	if (mlx->h_x < 0 || mlx->h_y < 0 || mlx->h_x > (mlx->cub3d.map.x * TILE_SIZE) || mlx->h_y > (mlx->cub3d.map.y * TILE_SIZE))
		return (1);
	if (mlx->v_x < 0 || mlx->v_y < 0 || mlx->v_x > (mlx->cub3d.map.x * TILE_SIZE) || mlx->v_y > (mlx->cub3d.map.y * TILE_SIZE))
		return (0);
	double h_len = sqrt(pow(mlx->h_x - mlx->cub3d.player.x, 2) + pow(mlx->h_y - mlx->cub3d.player.y, 2));
	double v_len = sqrt(pow(mlx->v_x - mlx->cub3d.player.x, 2) + pow(mlx->v_y - mlx->cub3d.player.y, 2));
	if (h_len < v_len)
		return (0);
	return (1);
}

void	ray(t_mlx *mlx, int color)
{
	//mlx->cub3d.player.rotation_angle = 0.1;

	if (sin(mlx->cub3d.player.rotation_angle) >= 0)
		ft_look_up(mlx);
	else
		ft_look_down(mlx);
	if (ft_compare(mlx))
	{
		//printf(">>>>\n");
		// printf("x = %f, y = %f\n", mlx->v_x, mlx->v_y);
		draw_line(mlx, mlx->cub3d.player.x, mlx->cub3d.player.y, mlx->v_x, mlx->v_y, color);
	}
	else
		draw_line(mlx, mlx->cub3d.player.x, mlx->cub3d.player.y, mlx->h_x, mlx->h_y, color);
}

