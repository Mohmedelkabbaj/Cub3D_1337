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
	t_parse_direction   parse_direct;
	t_rgb				floor;
	t_rgb				ceiling;
}	t_cub3d;


//+ Parsing cardinal Functions +//
int		start_parsing(t_cub3d *cub3d);
int		parse_direction(t_cub3d *cub3d, char *line);
void	free_array(char **array);
int		cardinal_direction(char *line);
void	fill_textures(char **split, t_cub3d *cub3d);
void	check_textures(t_cub3d *cub3d);

//+ Parsing RGB Functions +//

int		comma_check(char *line);
int		parse_floor_color(t_cub3d *cub3d, char *line, char type);
int		result_length(char *line);
int		check_isdigit(char *line);
int		check_rang_rgb(t_cub3d *cub3d, int r, int g, int b, char type);
char	*cut_rgb(char *rgb);
char	*get_rgb(char *line);

//+ Parsing Map Functions +//


//+Free Functions +//
void	free_array(char **array);
void	free_textures(t_cub3d *cub3d);
void	free_rgb(char *rgb, char *tmp);
#endif