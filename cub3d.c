/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:58 by hamaarou          #+#    #+#             */
/*   Updated: 2023/10/15 15:31:05 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/cub3d.h"

void	printf_test(t_cub3d cub3d)
{
	printf("NORTH : '%s'\n", cub3d.parse_direct.north_texture);
	printf("SOUTH : '%s'\n", cub3d.parse_direct.south_texture);	
	printf("EAST : '%s'\n", cub3d.parse_direct.east_texture);
	printf("WEST : '%s'\n", cub3d.parse_direct.west_texture);
	printf("FLOOR : '%d,%d,%d'\n", cub3d.floor.r, cub3d.floor.g, cub3d.floor.b);
	printf("CEILING : '%d,%d,%d'\n", cub3d.ceiling.r, cub3d.ceiling.g, cub3d.ceiling.b);
	int i = 0;
	while (cub3d.map_2d[i])
	{
		printf("MAP : {%s}\n", cub3d.map_2d[i]);
		i++;
	}
	printf("position x : %d\n", cub3d.player.x);
	printf("position y : %d\n", cub3d.player.y);
	printf("map x : %d\n", cub3d.map.x);
	printf("map y : %d\n", cub3d.map.y);
}


int main(int ac, char *av[])
{
	t_cub3d cub3d;
	init_all(&cub3d);
	if (ac == 2)
	{
		cub3d.file_name = av[1];
		cub3d.fd = open(cub3d.file_name, O_RDONLY);
		if (cub3d.fd == -1)
			return (1);
		if (start_parsing(&cub3d) == EXIT_FAILURE || config_file_is_set(cub3d) == EXIT_FAILURE)
		{
			ft_putendl_fd("\033[0;31m 📛Error Invalid Map📛 \033[0m", 2);
			return (free_all(&cub3d), 1);
		}
		else
		{
			/*
				Enter your Ray Casting code here
			*/
			
			//printf_test(cub3d);
			free_all(&cub3d);
		}
		
		close(cub3d.fd);
		return (0);
	}
	return (1);
}
