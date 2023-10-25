#include "../includes/cub3d.h"

void    player_calcule(t_cub3d *cub3d)
{
    cub3d->player.raduis = 0;
    cub3d->player.turn_direction = 0;
    cub3d->player.walk_direction = 0;
    cub3d->player.walk_speed = 1;
    cub3d->player.turn_speed = 2 * (M_PI / 180);
    cub3d->player.step = 0;
    cub3d->player.look = 0;
}