#include "../includes/cub3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int	i;
	int	j;

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
	int	x_center = player.x * TILE_SIZE + TILE_SIZE / 2;
	int	y_center = player.y * TILE_SIZE + TILE_SIZE / 2;
	int	radius = 3; // Adjust the radius to control the size of the mini-circle
	int	x = -radius;

	while (x <= radius)
	{
		int y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				int draw_x = x_center + x;
				int draw_y = y_center + y;
				my_mlx_pixel_put(&mlx->data, draw_x, draw_y, 0xff0000);
			}
			y++;
		}
		x++;
	}
}

void	update_player(t_player *player)
{
	float moveStep = player->walk_direction * player->walk_speed + player->step;
	
	player->rotation_angle += player->turn_direction * player->turn_speed;
	player->x = player->x + cos(player->rotation_angle) * moveStep;
	player->y = player->y + sin(player->rotation_angle) * moveStep;
}

int	key_release(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == KEY_UP)
		mlx->cub3d.player.walk_direction = 0;
	if (key == KEY_DOWN)
		mlx->cub3d.player.walk_direction = 0;
	if (key == KEY_RIGHT)
		mlx->cub3d.player.turn_direction = 0;
	if (key == KEY_LEFT)
		mlx->cub3d.player.turn_direction = 0;
	
	return (0);
}

void	render(t_mlx *mlx, t_cub3d cub3d)
{
	int	i;
	int	j;

	
	mlx->data.img = mlx_new_image(mlx->mlx_ptr, cub3d.map.x * 32, cub3d.map.y * 32);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel, &mlx->data.line_length, &mlx->data.endian);
	i = -1;
	while (++i < cub3d.map.x)
	{
		j = -1;
		while (++j < cub3d.map.y)
		{
			if (cub3d.map_2d[j][i] == '1')
				draw_square(mlx, i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, 0x000000);
			else if (cub3d.map_2d[j][i] == '0')
				draw_square(mlx, i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, 0xffffff);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	return ;	
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_UP)
		mlx->cub3d.player.walk_direction = 1;
	if (key == KEY_DOWN)
		mlx->cub3d.player.walk_direction = -1;
	if (key == KEY_RIGHT)
		mlx->cub3d.player.turn_direction = 1;
	if (key == KEY_LEFT)
		mlx->cub3d.player.turn_direction = -1;
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	game(t_mlx *mlx)
{
	//mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	render(mlx, mlx->cub3d);
	update_player(&mlx->cub3d.player);
	player_circle_render(mlx, mlx->cub3d.player);
	return (0);
}
