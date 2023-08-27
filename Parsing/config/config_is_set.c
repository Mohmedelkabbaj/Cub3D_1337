/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_is_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:05:01 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 17:07:07 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	config_file_is_set(t_cub3d cub3d)
{
	if (cub3d.ceiling.b == -1 || cub3d.ceiling.g == -1 || cub3d.ceiling.r == -1)
		return (EXIT_FAILURE);
	if (cub3d.floor.b == -1 || cub3d.floor.g == -1 || cub3d.floor.r == -1)
		return (EXIT_FAILURE);
	if (cub3d.parse_direct.north_texture == NULL || cub3d.parse_direct.south_texture == NULL
		|| cub3d.parse_direct.east_texture == NULL || cub3d.parse_direct.west_texture == NULL)
		return (EXIT_FAILURE);
	if (cub3d.map_2d == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
