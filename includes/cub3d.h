 /* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:49:02 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/22 17:45:51 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include<math.h>
#include <mlx.h>
#include "../Library/Libft/libft.h"
#include "../Library/Get_next_line/get_next_line.h"

#define TILE_SIZE 32
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define MAP_H 1080
#define MAP_W 1920

//Keys
#define KEY_UP 125
#define KEY_DOWN 126
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_ESC 53
typedef struct s_parse_direction
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
}	t_parse_direction;

typedef struct s_rgb
{
	int     r;
	int     g;
	int     b;
}	t_rgb;

typedef struct s_player
{
	int		x;
	int		y;
	int		raduis;
	int		turn_direction;//-1 for left +1 for right or left (help me with changing the position of the player )
	int		walk_direction;//-1 for back +1 for front or back
	double	rotation_angle;//angle in radian
	double	walk_speed;//the speed of the player
	double	turn_speed;//the turn speed of the player
	int step;
}	t_player;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	int		x;
	int		y;
}	t_map;
typedef struct s_cub3d{
	char				*file_name;
	int					fd;
	char				*map_1d;
	char				**map_2d;
	int					map_height;
	t_parse_direction   parse_direct;
	t_rgb				floor;
	t_rgb				ceiling;
	t_player			player;
	t_map				map;
}	t_cub3d;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	data;
	t_cub3d	cub3d;
}	t_mlx;

//!Parsing cardinal Functions +!//

//+initilization structure Functions +//
void	init_textures(t_cub3d *cub3d);
void	init_rgb(t_cub3d *cub3d);
void	init_map(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
void	init_all(t_cub3d *cub3d);

//+ Parsing cardinal Functions +//
int		start_parsing(t_cub3d *cub3d);
int		parse_direction(t_cub3d *cub3d, char *line);
void	free_array(char **array);
int		cardinal_direction(char *line);
int		fill_textures(char **split, t_cub3d *cub3d);
int		check_textures(t_cub3d *cub3d);

//+ Parsing RGB Functions +//
int		comma_check(char *line);
int		parse_floor_color(t_cub3d *cub3d, char *line, char type);
int		result_length(char *line);
int		check_isdigit(char *line);
int		check_rang_rgb(t_cub3d *cub3d, int r, int g, int b, char type);
char	*cut_rgb(char *rgb);
char	*get_rgb(char *line);
int		rgb(t_cub3d cub3d);
int		rgb_is_set(t_cub3d *cub3d);

//+ Parsing Map Functions +//
int		textures_is_fill(t_cub3d *cub3d);
int		floor_ceiling_is_color(t_cub3d *cub3d);
int		is_map_last(t_cub3d *cub3d);
void	map_height(t_cub3d *cub3d);
int		first_last_lines(char *line);
int		first_last_column(char *line);
int		is_surrounded(t_cub3d *cub3d);
int		map_check(t_cub3d *cub3d);
int		is_map(char *line);
char	**to_rectangle(char **map, size_t line_length);
size_t	tall_line(char **map);
char	*get_line(char *line, size_t max);
int		check_newline(char *map_1d);
void    map_dimension(t_cub3d *cub3d);

//*player*//
int 	num_of_player(t_cub3d *cub3d);
void    get_p_position(t_cub3d *cub3d);

//+config file
int		config_file_is_set(t_cub3d cub3d);

//+Free Functions +//
void	free_array(char **array);
void	free_textures(t_cub3d *cub3d);
void	free_rgb(char *rgb, char *tmp);
void	free_all(t_cub3d *cub3d);


//+Ray Casting Functions +//

void	player_calcule(t_cub3d *cub3d);
int		key_press(int key, t_mlx *mlx);
int		key_release(int key, t_mlx *mlx);

void	render(t_mlx *mlx, t_cub3d cub3d);
int		game(t_mlx *mlx);
int		close_window(t_mlx *mlx);

#endif