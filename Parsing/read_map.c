/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/22 18:56:34 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"


void	start_parsing(t_cub3d *cub3d)
{
	char	*line;

	line = get_next_line(cub3d->fd);
	while (line)
	{
		line = ft_strtrim(line, " ");
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(cub3d->fd);
			continue ;
		}
		if (cardinal_direction(line) == 1)
		{
			if (parse_direction(cub3d, line) == 1)
				exit(EXIT_FAILURE);
		}
		else if (line[0] == 'F')
			parse_floor_color(cub3d, line, 'F');
		else if (line[0] == 'C')
			parse_floor_color(cub3d, line, 'C');
		// else if (line[0] == '1' || line[0] == '0')
		// 	parse_map(cub3d, line);
		else
		{
			ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(cub3d->fd);
	}
}