/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:58 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/24 15:24:28 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/cub3d.h"
void	printf_test(t_cub3d cub3d)
{
	printf("NORTH : %s\n", cub3d.parse_direct.north_texture);
	printf("SOUTH : %s\n", cub3d.parse_direct.south_texture);	
	printf("EAST : %s\n", cub3d.parse_direct.east_texture);
	printf("WEST : %s\n", cub3d.parse_direct.west_texture);

	printf("FLOOR : %d %d %d\n", cub3d.floor.r, cub3d.floor.g, cub3d.floor.b);
	printf("CEILING : %d %d %d\n", cub3d.ceiling.r, cub3d.ceiling.g, cub3d.ceiling.b);

	printf("MAP : {%s}\n", cub3d.map_1d);
}


int main(int ac, char *av[])
{
	t_cub3d cub3d;

	init_textures(&cub3d);
	init_rgb(&cub3d);
	if (ac == 2)
	{
		cub3d.file_name = av[1];
		cub3d.fd = open(cub3d.file_name, O_RDONLY);
		if (cub3d.fd == -1)
			return (1);
		if (start_parsing(&cub3d) == EXIT_FAILURE)
		{
			free_textures(&cub3d);
			close(cub3d.fd);
			return (1);
		}
		check_textures(&cub3d);
		
		/*
			Enter your Ray Casting code here
		*/
		printf_test(cub3d);
		free(cub3d.map_1d);
		free_textures(&cub3d);
		close(cub3d.fd);
		return (0);
	}
	return (1);
}