/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:02:21 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/21 11:58:52 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cardinal_direction(char *line)
{

	if (line[0] == 'N' && line[1] == 'O')
		return (0);
	else if (line[0] == 'S' && line[1] == 'O')
		return (0);
	else if (line[0] == 'E' && line[1] == 'A')
		return (0);
	else if (line[0] == 'W' && line[1] == 'E')
		return (0);
	return (-1);
}

void	check_textures(t_cub3d *cub3d)
{
	if (cub3d->parse_direct.north_texture == NULL ||
		cub3d->parse_direct.south_texture == NULL ||
		cub3d->parse_direct.east_texture == NULL ||
		cub3d->parse_direct.west_texture == NULL)
	{
		ft_putendl_fd("Error\nMissing textures", 2);
		exit(1);
	}
	return ;
}