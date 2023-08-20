/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:49:02 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/19 17:05:37 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include "../Library/Libft/libft.h"
#include "../Library/Get_next_line/get_next_line.h"

typedef struct t_parse_direction
{
    char    *north;//no
    char    *south;//so
    char    *east;//ea
    char    *west;//we


}   t_parse_direction;

typedef struct t_cub3d{
    char    *file_name;
    int     fd;

    t_parse_direction   parse_direct;
    
}   t_cub3d;


void    start_parsing(t_cub3d *cub3d);
void    parse_direction(t_cub3d *cub3d, char *line);

int	cardinal_direction(char *line);



#endif