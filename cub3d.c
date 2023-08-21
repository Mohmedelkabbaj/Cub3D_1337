/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:58 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/21 14:52:11 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/cub3d.h"




int main(int ac, char *av[])
{
	t_cub3d cub3d;

	// cub3d.parse_direct.north_texture = NULL;
	// cub3d.parse_direct.south_texture = NULL;
	// cub3d.parse_direct.east_texture = NULL;
	// cub3d.parse_direct.west_texture = NULL;
	if (ac == 2)
	{
		cub3d.file_name = av[1];
		cub3d.fd = open(cub3d.file_name, O_RDONLY);
		if (cub3d.fd == -1)
			return (1);
		start_parsing(&cub3d);
		check_textures(&cub3d);
		printf("North : %s\n", cub3d.parse_direct.north_texture);
		printf("SOUTH : %s\n", cub3d.parse_direct.south_texture);
		printf("EAST : %s\n", cub3d.parse_direct.east_texture);
		printf("WEST : %s\n", cub3d.parse_direct.west_texture);
	}
	return (1);
}