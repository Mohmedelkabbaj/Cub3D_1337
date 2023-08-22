/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:49:02 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/22 11:55:05 by hamaarou         ###   ########.fr       */
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
    char    *north_texture;//no
    char    *south_texture;//so
    char    *east_texture;//ea
    char    *west_texture;//we

}   t_parse_direction;

typedef struct s_rgb
{
    int     r;
    int     g;
    int     b;
}   t_rgb;


typedef struct s_cub3d{
    char    *file_name;
    int     fd;

    t_parse_direction   parse_direct;
    t_rgb               floor;
    t_rgb               ceiling;
    
}   t_cub3d;


//+ Parsing cardinal Functions +//
void	start_parsing(t_cub3d *cub3d);
int     parse_direction(t_cub3d *cub3d, char *line);
void	free_array(char **array);
int		cardinal_direction(char *line);
void	fill_textures(char **split, t_cub3d *cub3d);
void	check_textures(t_cub3d *cub3d);

//+ Parsing RGB Functions +//
// ,,
// 3 number
// >= 0 && <= 255
// char
int	comma_check(char *line);
void	parse_floor_color(t_cub3d *cub3d, char *line);




//+ Parsing Map Functions +//


//+Free Functions +//
void	free_array(char **array);


#endif