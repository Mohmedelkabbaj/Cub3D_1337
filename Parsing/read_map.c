/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/25 18:00:18 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int start_parsing(t_cub3d *cub3d)
{
	char	*line;
	int		result;
	int		dir_result;
	//char	*map_line;

	result = EXIT_SUCCESS;

	while ((line = get_next_line(cub3d->fd)))
	{
		line = ft_strtrim(line, " ");
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		dir_result = cardinal_direction(line);
		if (dir_result == 1)
			result = parse_direction(cub3d, line);
		else if (line[0] == 'F' || line[0] == 'C')
			result = parse_floor_color(cub3d, line, line[0]);
		else if (line[0] == '1' || line[0] == '0')
		{
			if (is_map_last(cub3d))
			{
				cub3d->map_1d  = NULL;
				cub3d->map_2d = NULL;
				while (line)
				{
					cub3d->map_1d = ft_strjoin(cub3d->map_1d, line);
					free(line);
					line = NULL;
					line = get_next_line(cub3d->fd);
				}
				cub3d->map_2d = ft_split(cub3d->map_1d, '\n');
				map_height(cub3d);
				if (map_check(cub3d) == 1)
					result = EXIT_FAILURE;
			}
		}
		else
			result = EXIT_FAILURE;
		free(line);
		if (result == EXIT_FAILURE)
		{
			ft_putendl_fd("\033[0;31m 📛Error Invalid Map📛 \033[0m", 2);
			break;
		}
	}
	return (result);
}
