/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:02:21 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/19 17:05:54 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	cardinal_direction(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	else if (line[0] == 'S' && line[1] == 'O')
		return (2);
	else if (line[0] == 'E' && line[1] == 'A')
		return (3);
	else if (line[0] == 'W' && line[1] == 'E')
		return (4);
	return (-1);
}
