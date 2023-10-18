#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_mlx *mlx, int x, int y, int size, int color)
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

void player_circle_render(t_mlx *mlx, t_player player, int color)
{
	int x_center = player.x * TILE_SIZE + TILE_SIZE / 2;
	int y_center = player.y * TILE_SIZE + TILE_SIZE / 2;
	int radius = 8; // Adjust the radius to control the size of the mini-circle

	int x = -radius;
	while (x <= radius)
	{
		int y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				int draw_x = x_center + x;
				int draw_y = y_center + y;
				my_mlx_pixel_put(&mlx->data, draw_x, draw_y, color);
			}
			y++;
		}
		x++;
	}
}



void	render(t_mlx *mlx, t_cub3d cub3d)
{
	
	mlx->mlx_ptr = mlx_init();
	player_calcule(&cub3d);
	mlx->data.img = mlx_new_image(mlx->mlx_ptr, cub3d.map.x * 32, cub3d.map.y * 32);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel, &mlx->data.line_length, &mlx->data.endian);
	mlx->mlx_win  = mlx_new_window(mlx->mlx_ptr, cub3d.map.x * 32, cub3d.map.y * 32, "Cub3D");
	int i = 0;
	int j;
	while (i < cub3d.map.x)
	{
		j = 0;
		while (j < cub3d.map.y)
		{
			if (cub3d.map_2d[j][i] == '0' || cub3d.map_2d[j][i] == 'E' || cub3d.map_2d[j][i] == 'W' || cub3d.map_2d[j][i] == 'N' || cub3d.map_2d[j][i] == 'S')
				draw_square(mlx, i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, 0xffffff);
			else
				draw_square(mlx, i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, 0x000000);           
			j++;
		}
		i++;
	}
	player_circle_render(mlx, cub3d.player, 0xff0000);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	mlx_loop(mlx->mlx_ptr);
}