/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:58 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/24 12:16:20 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/cub3d.h"

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

		
		free_textures(&cub3d);
		close(cub3d.fd);
		return (0);
	}
	return (1);
}