
#include "../../includes/cub3d.h"

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
	if(key == VIEW_UP)
		mlx->cub3d.player.look = 0;
	if (key == VIEW_DOWN)
		mlx->cub3d.player.look = 0;
	
	return (0);
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
	if (key == VIEW_UP)
		mlx->cub3d.player.look += 5;
	if (key == VIEW_DOWN)
		mlx->cub3d.player.look -= 5;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		printf("[ESC] close window]\n");
		exit(0);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	printf("close window\n");
	exit(0);
}

void  move_down_up(t_mlx *mlx)
{
	float moveStep = mlx->cub3d.player.walk_speed * mlx->cub3d.player.walk_direction;
	float newPlayerX = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle) * moveStep;
	float newPlayerY = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle) * moveStep;

	if (check_wall(mlx, newPlayerX, newPlayerY) == 0)
	{
		mlx->cub3d.player.x = newPlayerX;
		mlx->cub3d.player.y = newPlayerY;
	}
}

void  move_left_right(t_mlx *mlx)
{
	float moveStep = mlx->cub3d.player.walk_speed * mlx->cub3d.player.turn_direction;
	float newPlayerX = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle + M_PI_2) * moveStep;
	float newPlayerY = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle + M_PI_2) * moveStep;

	if (check_wall(mlx, newPlayerX, newPlayerY) == 0)
	{
		mlx->cub3d.player.x = newPlayerX;
		mlx->cub3d.player.y = newPlayerY;
	}
}

