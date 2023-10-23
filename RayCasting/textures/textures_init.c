#include "../includes/cub3d.h"

void    textures_data(t_mlx *mlx)
{
    mlx->data.path.north = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.north_texture,
            &mlx->data.north.width, &mlx->data.north.height);
    mlx->data.path.west = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.west_texture,
            &mlx->data.west.width, &mlx->data.west.height);
    mlx->data.path.south = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.south_texture,
            &mlx->data.south.width, &mlx->data.south.height);
    mlx->data.path.east = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.east_texture,
            &mlx->data.east.width, &mlx->data.east.height);
}

void textures_init(t_mlx *mlx)
{
    textures_data(mlx);
    if (!mlx->data.path.north || !mlx->data.path.west || !mlx->data.path.south || !mlx->data.path.east)
    {
        ft_putendl_fd("\033[0;31m 📛Error Invalid Texture📛 \033[0m", 2);
        free_all(&mlx->cub3d);
        exit(1);
    }
    mlx->data.north.addr = (int *)mlx_get_data_addr(mlx->data.path.north, &mlx->data.north.bits_per_pixel,
            &mlx->data.north.line_length, &mlx->data.north.endian);
    mlx->data.west.addr = (int *)mlx_get_data_addr(mlx->data.path.west, &mlx->data.west.bits_per_pixel,
            &mlx->data.west.line_length, &mlx->data.west.endian);
    mlx->data.south.addr = (int *)mlx_get_data_addr(mlx->data.path.south, &mlx->data.south.bits_per_pixel,
            &mlx->data.south.line_length, &mlx->data.south.endian);
    mlx->data.east.addr = (int *)mlx_get_data_addr(mlx->data.path.east, &mlx->data.east.bits_per_pixel,
            &mlx->data.east.line_length, &mlx->data.east.endian);
}
