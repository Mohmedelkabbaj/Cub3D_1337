#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&mlx->data, x + i, y + j, color);
			if (i == 0 || j == 0 || i == size || j == size)
				my_mlx_pixel_put(&mlx->data, x + i, y + j, 0x000000);
			j++;
		}
		i++;
	}
}

void player_circle_render(t_mlx *mlx, t_player player)
{
	double radius = 3.5;
	int color = 0xff0000;

	int x = -radius;
	while (x <= radius)
	{
		int y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(&mlx->data, player.x + x, player.y + y, color);
			y++;
		}
		x++;
	}
}



void render(t_mlx *mlx, t_cub3d cub3d)
{
	int i;
	int j;

	mlx->data.img = mlx_new_image(mlx->mlx_ptr, cub3d.map.x * 32, cub3d.map.y * 32);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel, &mlx->data.line_length, &mlx->data.endian);

	i = 0;
	while (i < cub3d.map.x)
	{
		j = 0;
		while (j < cub3d.map.y)
		{
			if (cub3d.map_2d[j][i] == '1')
				draw_square(mlx, i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, 0x000000);
			else if (cub3d.map_2d[j][i] == '0' || is_player(cub3d.map_2d[j][i]))
				draw_square(mlx, i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, 0xffffff);
			j++;
		}
		i++;
	}
	player_circle_render(mlx, mlx->cub3d.player);
	ray(mlx, 0x00ff00);
	//cast_ray(mlx->cub3d.player.rotation_angle, mlx, 0xff0000);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	return;
}

int game(t_mlx *mlx)
{
	if (mlx->cub3d.player.walk_direction)
	{
		//move_down_up(mlx);
		//render(mlx, mlx->cub3d);
	}
	if (mlx->cub3d.player.turn_direction)
	{
		look_left_right(mlx);
		//render(mlx, mlx->cub3d);
	}
	if (mlx->cub3d.player.look)
	{
		look_left_right(mlx);
	}
		render(mlx, mlx->cub3d);
	return (0);
}
