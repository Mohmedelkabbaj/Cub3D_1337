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
#include "../Library/Libft/libft.h"
#include "../Library/Get_next_line/get_next_line.h"

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

typedef struct s_cub3d{
	char				*file_name;
	int					fd;
	char				*map_1d;
	char				**map_2d;
	int					map_height;
	t_parse_direction   parse_direct;
	t_rgb				floor;
	t_rgb				ceiling;
}	t_cub3d;


//+initilization structure Functions +//
void	init_textures(t_cub3d *cub3d);
void	init_rgb(t_cub3d *cub3d);
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

//+Free Functions +//
void	free_array(char **array);
void	free_textures(t_cub3d *cub3d);
void	free_rgb(char *rgb, char *tmp);
void	free_all(t_cub3d *cub3d);
#endif