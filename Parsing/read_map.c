/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/19 17:08:25 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/cub3d.h"

void	start_parsing(t_cub3d *cub3d)
{
	char	*line;

	line = get_next_line(cub3d->fd);
	while (line)
	{
		line = ft_strtrim(line, " ");
		if (cardinal_direction(line) != -1)
			parse_direction(cub3d, line);
		else if (line[0] == 'R')
			parse_resolution(cub3d, line);
		else if (line[0] == 'F')
			parse_floor_color(cub3d, line);
		else if (line[0] == 'C')
			parse_ceiling_color(cub3d, line);
		else if (line[0] == '1' || line[0] == '0')
			parse_map(cub3d, line);
		else
			ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);/

		line = get_next_line(cub3d->fd);
	}
}