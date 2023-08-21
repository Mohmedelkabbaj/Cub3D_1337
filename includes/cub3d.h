/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:49:02 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/21 15:14:43 by hamaarou         ###   ########.fr       */
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

void	start_parsing(t_cub3d *cub3d);
void	parse_direction(t_cub3d *cub3d, char *line);
void	free_array(char **array);
int		cardinal_direction(char *line);
int		fill_textures(char **split, t_cub3d *cub3d);
void	check_textures(t_cub3d *cub3d);



#endif